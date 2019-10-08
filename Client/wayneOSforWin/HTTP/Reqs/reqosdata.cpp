﻿#include "reqosdata.h"

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

	// ~ Modified by LEE Jeun jeun@wayne-inc.com
	//if (infoManager->mVersionType == InfoManager::PAID) jsonObject.insert("productID", "");
	//else jsonObject.insert("productID", productID);
	jsonObject.insert("productID", productID);
	// Modified by LEE Jeun jeun@wayne-inc.com

	jsonObject.insert("vendorID", vendorID);
	jsonObject.insert("productRevision", productRevision);
	jsonObject.insert("serialNumber", serialNumber);
	// ~ Added by LEE jeun jeun@wayne-inc.com
	DOUBLE realCapacity = GetSelectedDiskCapacity();
	qDebug() << "real capacity: " << realCapacity << "GB";
	//jsonObject.insert("realCapacity", realCapacity);

	qDebug() << HttpManager::GetInstance()->httpThread.IPAddr;
	//jsonObject.insert("userIPAddress", HttpManager::GetInstance()->httpThread.IPAddr);
	
	/*int ramSize = getRamCapacity();
	qDebug() << "RAM Capacity: " << ramSize;
	jsonObject.insert("ramSize", ramSize);
	
	int ramClockSpeed = getRamClockSpeed();
	qDebug() << "RAM Clock Speed: " << ramClockSpeed;
	jsonObject.insert("ramClockSpeed", ramClockSpeed);*/
	RAM = getRamInfo();
	qDebug() << RAM.byteToGB() << "GB";
	//jsonObject.insert("ramSize", RAM.byteToGB());

	qDebug() << RAM.ClockSpeed << "MHz";
	//jsonObject.insert("ramClockSpeed", RAM.ClockSpeed);

	OS = getOSInfo();
	QString LocalOSver = OS.OSver.c_str(), LocalOSbit = QString::fromWCharArray(OS.bit);
	qDebug() << LocalOSver << " " << LocalOSbit;
	//jsonObject.insert("LocalOSinfo", LocalOSver + " " + LocalOSbit);

	QString CPU = GetCpuName();
	//jsonObject.insert("customerInfo0", "CPU: " + CPU);
	qDebug() << CPU;
	//jsonObject.insert("CPU", CPU);

	QString GPU = GetGpuName();
	//jsonObject.insert("customerInfo1", "GPU: " + GPU);
	qDebug() << GPU;
	//jsonObject.insert("GPU", GPU);
	// Added by LEE jeun jeun@wayne-inc.com ~
	
	// ~ Modified by LEE jeun jeun@wayne-inc.com
	QList<QHostAddress> list = QNetworkInterface::allAddresses();

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

	} 
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

std::string ReqOsData::getHwInfo(const TCHAR command[])
{
	TCHAR cmd[BUFSIZE];
	lstrcpy(cmd, command);
	HANDLE hChildStdOut_Rd = NULL, hChildStdOut_Wr = NULL;
	CHAR Buf[BUFSIZE];
	memset(Buf, 0, sizeof(Buf));
	std::string Data;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	CreatePipe(&hChildStdOut_Rd, &hChildStdOut_Wr, &sa, 0);
	SetHandleInformation(hChildStdOut_Rd, HANDLE_FLAG_INHERIT, 0);
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.hStdInput = NULL;
	si.hStdOutput = hChildStdOut_Wr;
	si.dwFlags |= STARTF_USESTDHANDLES;
	si.wShowWindow = SW_HIDE;
	CreateProcess(NULL, cmd, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
	DWORD dwRead = 0, dwOut = 0;
	while (PeekNamedPipe(hChildStdOut_Rd, NULL, 0, NULL, &dwOut, NULL))
	{
		if (dwOut <= 0 && WaitForSingleObject(pi.hProcess, 0) != WAIT_TIMEOUT) break;
		while (PeekNamedPipe(hChildStdOut_Rd, NULL, 0, NULL, &dwOut, NULL) && dwOut > 0)
		{
			ReadFile(hChildStdOut_Rd, Buf, sizeof(Buf), &dwRead, NULL);
			Buf[dwRead] = 0;
			Data += std::string(Buf);
		}
	}
	CloseHandle(hChildStdOut_Rd);
	CloseHandle(hChildStdOut_Wr);
	return Data;
}

/*int ReqOsData::getRamCapacity()
{
	std::vector<std::string> infoArray;
	std::string Data = getHwInfo(_T(RAM_CAPACITY_QUERY_STRING));
	std::string capacity_str;
	bool toggle = false;
	for (auto it = Data.begin(); it != Data.end(); ++it)
	{
		if (*it >= '0' && *it <= '9') toggle = true;
		else toggle = false;
		if (toggle) capacity_str += *it;
		if (!toggle && capacity_str.size() != 0)
		{
			infoArray.push_back(capacity_str);
			capacity_str.clear();
		}
	}
	long long RamCapacity = 0;
	for (int i = 0; i < infoArray.size(); ++i) RamCapacity += atoll(infoArray[i].c_str());
	return RamCapacity / (DIV*DIV*DIV);
}

int ReqOsData::getRamClockSpeed()
{
	std::string Data = getHwInfo(_T(RAM_CLOCK_SPEED_QUERY_STRING));
	std::string clock_speed_str;
	bool toggle = false;
	for (auto it = Data.begin(); it != Data.end(); ++it)
	{
		if (*it >= '0' && *it <= '9') toggle = true;
		else toggle = false;
		if (toggle) clock_speed_str += *it;
		if (!toggle && clock_speed_str.size() != 0) break;
	}
	int RamClockSpeed = atoi(clock_speed_str.c_str());
	return RamClockSpeed;
}*/

RamInfo ReqOsData::getRamInfo()
{
	RamInfo ri;
	memset(&ri, 0, sizeof(ri));
	std::vector<std::string> infoArray;
	std::string tmp;
	bool toggle = false;
	int cnt = 0;
	memset(&ri, 0, sizeof(ri));
	std::string Data = getHwInfo(_T(RAM_INFO_QUERY_STRING));
	for (auto it = Data.begin(); it != Data.end(); ++it)
	{
		if (*it != ' ' && *it != '\r' && *it != '\n') toggle = true;
		else
		{
			cnt = *it == ' ' ? cnt + 1 : cnt;
			toggle = false;
		}
		if (toggle) tmp += *it;
		else
		{
			if (cnt > 1)
			{
				if (!tmp.empty() && tmp.find("  ", 0) == std::string::npos)
				{
					infoArray.push_back(tmp);
					tmp.clear();
					cnt = 0;
				}
			}
		}
	}
	for (int i = 2; i < infoArray.size(); ++i)
	{
		if (i % 2 == 0)
		{
			ri.capacity += atoll(infoArray[i].c_str());
		}
	}
	ri.ClockSpeed = atoi(infoArray[infoArray.size() - 1].c_str());
	return ri;
}

OSInfo ReqOsData::getOSInfo()
{
	OSInfo oi;
	std::vector<std::string> infoArray;
	std::string tmp;
	bool toggle = false;
	int cnt = 0;
	memset(&oi, 0, sizeof(oi));
	std::string Data = getHwInfo(_T(LOCAL_OS_INFO_QUERY_STRING));
	for (auto it = Data.begin(); it != Data.end(); ++it)
	{
		if (*it != ' ' && *it != '\r' && *it != '\n') toggle = true;
		else
		{
			cnt = *it == ' ' ? cnt + 1 : cnt;
			toggle = false;
		}
		if (toggle) tmp += *it;
		else
		{
			if (cnt > 1)
			{
				if (!tmp.empty() && tmp.find("  ", 0) == std::string::npos)
				{
					infoArray.push_back(tmp);
					tmp.clear();
					cnt = 0;
				}
			}
		}
		cnt = toggle || cnt > 1 ? 0 : cnt;
	}
	oi.OSver = infoArray[2];
	char tmpBuf[8];
	strcpy(tmpBuf, infoArray[3].c_str());
	MultiByteToWideChar(CP_ACP, 0, tmpBuf, sizeof(tmpBuf), oi.bit, sizeof(oi.bit));
	return oi;
}

QString ReqOsData::GetGpuName()
{
	std::string Data = getHwInfo(_T(GPU_INFO_QUERY_STRING));
	int start = 0, end = 0;
	start = Data.find("\n") + 1;
	end = Data.find("  ", start);
	QString ProcessorName = Data.substr(start, end - start).c_str();
	return ProcessorName;
}

DOUBLE ReqOsData::GetSelectedDiskCapacity()
{
	QString path = InfoManager::GetInstance()->mDriveInstallPath.section("", 2, 3);
	TCHAR DrivePath[8];
	memset(DrivePath, 0, sizeof(DrivePath));
	path.toWCharArray(DrivePath);
	ULARGE_INTEGER lpFreeByteAvailableToCaller, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes;
	//UINT DiskType = GetDriveType(DrivePath);
	BOOL bResult = GetDiskFreeSpaceEx(DrivePath, &lpFreeByteAvailableToCaller, &lpTotalNumberOfBytes, &lpTotalNumberOfFreeBytes);
	if (!bResult) return 0;
	DOUBLE selectedDiskCapacity = (lpTotalNumberOfBytes.QuadPart) / (1024.0*1024.0*1024.0);
	return selectedDiskCapacity;
}
/*QString ReqOsData::GetGpuName()
{
	HANDLE hChildStdOut_Rd = NULL, hChildStdOut_Wr = NULL;
	TCHAR cmd[] = _T(GPU_INFO_QUERY_STRING);
	CHAR Buf[BUFSIZE];
	memset(Buf, 0, sizeof(Buf));
	std::string Data;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	CreatePipe(&hChildStdOut_Rd, &hChildStdOut_Wr, &sa, 0);
	SetHandleInformation(hChildStdOut_Rd, HANDLE_FLAG_INHERIT, 0);
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.hStdInput = NULL;
	si.hStdOutput = hChildStdOut_Wr;
	si.dwFlags |= STARTF_USESTDHANDLES;
	si.wShowWindow = SW_HIDE;
	CreateProcess(NULL, cmd, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	DWORD dwRead = 0, dwOut = 0;
	while (PeekNamedPipe(hChildStdOut_Rd, NULL, 0, NULL, &dwOut, NULL))
	{
		if (dwOut <= 0 && WaitForSingleObject(pi.hProcess, 0) != WAIT_TIMEOUT) break;
		while (PeekNamedPipe(hChildStdOut_Rd, NULL, 0, NULL, &dwOut, NULL) && dwOut > 0)
		{
			ReadFile(hChildStdOut_Rd, Buf, sizeof(Buf), &dwRead, NULL);
			Data += std::string(Buf);
		}
	}
	CloseHandle(hChildStdOut_Rd);
	int start = 0, end = 0;
	start = Data.find("\n") + 1;
	end = Data.find("  ", start);
	QString ProcessorName = Data.substr(start, end - start).c_str();
	return ProcessorName;
}*/
// Added by LEE jeun jeun@wayne-inc.com ~

