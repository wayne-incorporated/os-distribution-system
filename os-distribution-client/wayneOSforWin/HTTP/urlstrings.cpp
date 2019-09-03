#include "urlstrings.h"

UrlStrings::UrlStrings()
{
	//URL = "http://wayne-inc.co:8080/"; // Modified by Ainesh ainesh@wayne-inc.com <Official site>
	//URL = "http://35.236.41.225:8080/"; // wayne-os-server-official
	URL = "http://localhost:8080";
	//URL = "http://34.94.29.98:8080"; // wayne-os-server-dev

    URLMainInfo = URL + "/resources/Info/mainInfo-Eng.html";
    URLLicenseInfo = URL + "/resources/Info/licenseInfo-Eng.html";

    URLOSData = "/OSData.do";
    URLOSFile = "/OSFileDownwload.do";
    URLDeviceVolume="/devicevolume/volumeAllToClient.do";
}

UrlStrings::~UrlStrings()
{

}

