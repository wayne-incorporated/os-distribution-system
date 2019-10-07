#include "reqosfile.h"

#include "../httpheaders.h"
#include "../urlstrings.h"

ReqOsFile::ReqOsFile(QNetworkAccessManager* manager, QString updateFileName, int slideIndex, int slideCount)
{
    this->slideIndex = slideIndex;
    this->slideCount = slideCount;
	this->updateFileName = updateFileName;
    UrlStrings urlStrings;
    QUrl url(urlStrings.URL + urlStrings.URLOSFile);

    QNetworkRequest request(url);

	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    manager->post(request,CreateData().toJson());
}


ReqOsFile::~ReqOsFile()
{

}
QJsonDocument ReqOsFile::CreateData()
{
    QJsonObject jsonObject;
	jsonObject.insert("updateFileName", this->updateFileName);
    jsonObject.insert("slideIndex",this->slideIndex);
    jsonObject.insert("slideCount",this->slideCount);


    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);
    qDebug()<<"send Data : "<<jsonDoc.toJson()<<endl;

    return jsonDoc;

}

