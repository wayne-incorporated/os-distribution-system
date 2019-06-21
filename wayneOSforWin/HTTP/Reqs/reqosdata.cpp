#include "reqosdata.h"

#include "../httpheaders.h"
#include "../urlstrings.h"

#include "../../Info/infomanager.h"
#include "../../Disk/diskmanager.h"

#include "HTTP/httpmanager.h"
#include "HTTP/httpthread.h"

#include <qnetworkinterface>


ReqOsData::ReqOsData(QNetworkAccessManager* manager)
{
    UrlStrings urlStrings;
    QUrl url(urlStrings.URL + urlStrings.URLOSData);

    QNetworkRequest request(url);

    request.setRawHeader("Content-Type", "application/json;charset=UTF-8");
    manager->post(request,GetInstallInfoData().toJson());
}

ReqOsData::~ReqOsData()
{

}

QJsonDocument ReqOsData::GetInstallInfoData()
{
    InfoManager* infoManager = InfoManager::GetInstance();

    QJsonObject jsonObject;
    QJsonDocument jsonDoc;

    if(infoManager->mVersionType == InfoManager::FREE) jsonObject.insert("versionType","FREE");
    else if(infoManager->mVersionType == InfoManager::PAID) jsonObject.insert("versionType","PAID");

    //Device Type Check
    if(infoManager->mDeviceType == InfoManager::USB) jsonObject.insert("deviceType","USB");
    else if(infoManager->mDeviceType == InfoManager::SSD) jsonObject.insert("deviceType","SSD");

   
	jsonObject.insert("deviceVolume",QString::number(infoManager->mSize));
	//USB or SSD Info(ex. serial Number...)
	QString serialNumber = DiskManager::GetInstance()->mSerialNumber.trimmed();
	QString productID = DiskManager::GetInstance()->mProductId.trimmed();
	QString vendorID = DiskManager::GetInstance()->mVendorId.trimmed();
	QString productRevision = DiskManager::GetInstance()->mProductRevision.trimmed();

	if (infoManager->mVersionType == InfoManager::PAID) jsonObject.insert("productID", "");
	else jsonObject.insert("productID", productID);
	
	jsonObject.insert("vendorID", vendorID);
	jsonObject.insert("productRevision", productRevision);
	jsonObject.insert("serialNumber", serialNumber);
	// ~ Added by LEE jeun jeun@wayne-inc.com
	qDebug() << HttpManager::GetInstance()->httpThread.IPAddr;
	jsonObject.insert("userIPAddress", HttpManager::GetInstance()->httpThread.IPAddr);

	QString CPU = GetCpuName();
	qDebug() << CPU;
	jsonObject.insert("customerInfo0", "CPU: " + CPU);

	QString GPU = GetGpuName();
	qDebug() << GPU;
	jsonObject.insert("customerInfo1", "GPU: " + GPU);
	// Added by LEE jeun jeun@wayne-inc.com ~
	
	// ~ Modified by LEE jeun jeun@wayne-inc.com
	/*QList<QHostAddress> list = QNetworkInterface::allAddresses();

	for (int nIter = 0; nIter<list.count(); nIter++)

	{
		if (!list[nIter].isLoopback())
		{

			if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol)
			{
				qDebug() << list[nIter].toString();
				jsonObject.insert("userIPAddress", list[nIter].toString());
				break;
			}
		}

	}*/ 
	// Modified by LEE jeun jeun@wayne-inc.com ~
    jsonDoc.setObject(jsonObject);
    qDebug()<<"send Data : "<<jsonDoc.toJson()<<endl;
    return jsonDoc;

}

// ~ Added by LEE jeun jeun@wayne-inc.com
QString ReqOsData::GetCpuName()
{
	QString ProccessorName;
	int CPUInfo[4] = { -1 };
	char CPUBrandString[0x40];
	__cpuid(CPUInfo, ID);
	unsigned int nExIDs = CPUInfo[0];
	memset(CPUBrandString, 0, sizeof(CPUBrandString));
	for (int i = ID; i <= nExIDs; ++i)
	{
		__cpuid(CPUInfo, i);
		if (i == ID + 2) memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if (i == ID + 3) memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if (i == ID + 4) memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}
	int size = strlen(CPUBrandString);
	for (int i = 0; i < size - 2; ++i)
	{
		if (CPUBrandString[i] == ' ' && CPUBrandString[i + 1] == ' ' && CPUBrandString[i + 2] == ' ') CPUBrandString[i] = 0;
	}
	ProccessorName = CPUBrandString;
	return ProccessorName;
}

QString ReqOsData::GetGpuName()
{
	FILE* fp;
	char path[PATH_MAX];
	memset(path, -1, PATH_MAX);
	QString ProcessorName;
	fp = _popen(GPU_INFO_QUERY_STRING.c_str(), "r");
	if (fp != NULL)
	{
		while (fgets(path, PATH_MAX, fp) != NULL)
		{
			if (std::string(path).find("\r") == 0) continue;
			else if (std::string(path).find("Name") == std::string::npos)
			{
				int eos = std::string(path).find("  ");
				ProcessorName = std::string(path).substr(0, eos).c_str();
			}
		}
		_pclose(fp);
	}
	return ProcessorName;
}
// Added by LEE jeun jeun@wayne-inc.com ~


