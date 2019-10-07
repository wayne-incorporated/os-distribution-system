
#include <QApplication>
#include <QStyleFactory>



#include "View/CustomControl/frametitlebar.h"

#include "View/stackedwidget.h"
#include "HTTP/httpmanager.h"
#include "View/viewmanager.h"


int main(int argc, char *argv[])
{
	// ~ Added by LEE Jeun jeun@wayne-inc.com 
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
