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
#include <atlstr.h>
#include <vector>

#define ID 0x80000000
// ~ Modified and Added by LEE Jeun jeun@wayne-inc.com
#define BUFSIZE 128
#define DIV 1024
#define CPU_INFO_QUERY_STRING "wmic cpu get name"
#define GPU_INFO_QUERY_STRING "wmic path Win32_VideoController get name"
#define RAM_INFO_QUERY_STRING "wmic memorychip get capacity, speed"
#define LOCAL_OS_INFO_QUERY_STRING "wmic os get caption, osarchitecture"
//#define RAM_CAPACITY_QUERY_STRING "wmic memorychip get capacity"
//#define RAM_CLOCK_SPEED_QUERY_STRING "wmic memorychip get speed"
// Modified and Added by LEE Jeun jeun@wayne-inc.com ~

typedef struct _RAMINFO
{
	long long capacity;
	int ClockSpeed;
	int byteToGB() { return capacity / (DIV*DIV*DIV); }
}RamInfo;

typedef struct _OSINFO
{
	std::string OSver;
	TCHAR bit[8];
}OSInfo;

class ReqOsData
{
public:
    ReqOsData(QNetworkAccessManager* manager);
    ~ReqOsData();
	QJsonDocument GetInstallInfoData();
	// ~ Added by LEE jeun jeun@wayne-inc.com
	QString GetCpuName(); 
	QString GetGpuName(); 
	RamInfo RAM;
	OSInfo OS;
	std::string getHwInfo(const TCHAR command[]);
	RamInfo getRamInfo();
	OSInfo getOSInfo();
	LONGLONG GetSelectedDiskCapacity();
	//int getRamCapacity();
	//int getRamClockSpeed();
	// Added by LEE Jeun jeun@wayne-inc.com ~
};


#endif // REQOSDATA_H
