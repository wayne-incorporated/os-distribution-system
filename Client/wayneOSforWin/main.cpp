
#include <QApplication>
#include <QStyleFactory>



#include "View/CustomControl/frametitlebar.h"

#include "View/stackedwidget.h"
#include "HTTP/httpmanager.h"
#include "View/viewmanager.h"

// this function is for saving logs when running the client, Added by LEE Jeun@wayne-inc.com
//void LogToFile(QtMsgType, const QMessageLogContext&, const QString&);

/*void LogToFile(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	if (!QFile::exists("logs"))
	{
		QDir dir;
		dir.mkdir("logs");
	}
	
	QFile file("logs/log.txt");
	
	if (!file.open(QIODevice::Append | QIODevice::Text))
	{
		return;
	}

	QTextStream out(&file);

	QString curtime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

	switch (type)
	{
	case QtDebugMsg:
		out << "[Debug] : " << curtime << " " << msg << "\n";
		break;
	case QtInfoMsg:
		out << "[Info] : " << curtime << " " << msg << "\n";
		break;
	case QtWarningMsg:
		out << "[Warning] : " << curtime << " " << msg << "\n";
		break;
	case QtCriticalMsg:
		out << "[Critical] : " << curtime << " " << msg << context.function << " " << context.line << "\n";
		break;
	case QtFatalMsg:
		out << "[Fatal] : " << curtime << " " << msg << "\n";
		abort();
	}
	
	out << "\n";

	file.close();
}*/

int main(int argc, char *argv[])
{
	// ~ Added by LEE Jeun jeun@wayne-inc.com
	//qInstallMessageHandler(LogToFile);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	// Added by LEE Jeun jeun@wayne-inc.com ~
	QApplication a(argc, argv);
	//background - white
	QPalette pal = a.palette();
	pal.setColor(QPalette::Window, Qt::white);
	a.setPalette(pal);
	//set Icon
	QIcon icon("icon.ico");
	a.setWindowIcon(icon);

	//create view Object
	StackedWidget* stackedWidget = new StackedWidget();

	//title bar Create..
	FrameTitleBar box;

	QVBoxLayout *l = new QVBoxLayout(box.contentWidget());
	l->setMargin(0);

	l->addWidget(stackedWidget);
	box.show();

	//add views..
	ViewManager::GetInstance()->setStackedWidget(stackedWidget);
	stackedWidget->setCurrentIndex(0);

	//http thread call
	HttpManager* httpManager = HttpManager::GetInstance();
	httpManager->DoWork();


	return a.exec();
}
