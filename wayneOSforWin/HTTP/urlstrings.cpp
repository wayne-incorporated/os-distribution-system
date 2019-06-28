#include "urlstrings.h"

UrlStrings::UrlStrings()
{
    //URL = "http://localhost:8080/";
    //URL ="http://211.110.130.61:8080";
	URL = "http://wayne-inc.co:8080/"; // Modified by Ainesh ainesh@wayne-inc.com <Official site>
	//URL = "http://35.201.242.225:8080/"; // Added by LEE Jeun jeun@wayne-inc.com <for testing> 
	//URL = "http://35.233.137.186:8080/"; // This ip address is for US server.
	//URL = "http://35.201.198.249:8080/"; // This ip address is for Asian server.
	//URL = "http://35.243.164.73:8080/";

    URLMainInfo = URL + "/resources/Info/mainInfo-Eng.html";
    URLLicenseInfo = URL + "/resources/Info/licenseInfo-Eng.html";

    URLOSData = "/OSData.do";
    URLOSFile = "/OSFileDownwload.do";
    URLDeviceVolume="/devicevolume/volumeAllToClient.do";
}

UrlStrings::~UrlStrings()
{

}

