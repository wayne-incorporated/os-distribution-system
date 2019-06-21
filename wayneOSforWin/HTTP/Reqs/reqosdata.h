#ifndef REQOSDATA_H
#define REQOSDATA_H


#include <QtNetwork/QNetworkAccessManager>
#include <QSysInfo>
#include <intrin.h>
#include <Windows.h>
#include <cstdio>
#include <cstring>
#include <QString>
#include <string>
#include <fstream>

#define ID 0x80000000
#define PATH_MAX 64

const std::string GPU_INFO_QUERY_STRING = "wmic path Win32_VideoController get name";

class ReqOsData
{
public:
    ReqOsData(QNetworkAccessManager* manager);
    ~ReqOsData();
    
	QJsonDocument GetInstallInfoData();
	QString GetCpuName(); // Added by LEE jeun jeun@wayne-inc.com
	QString GetGpuName(); // Added by LEE Jeun jeun@wayne-inc.com
};


#endif // REQOSDATA_H
