#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent)
{
    // Don't let this widget inherit the parent's backround color
    setAutoFillBackground(true);
    // Use a brush with a Highlight color role to render the background
    setBackgroundRole(QPalette::Highlight);

    imageLabel = new QLabel(this);
    minimize = new QToolButton(this);
    close= new QToolButton(this);

    // Use the style to set the button pixmaps
    QPixmap pix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    close->setIcon(pix);


    pix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minimize->setIcon(pix);

    restorePix = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);

    minimize->setMinimumHeight(20);
    close->setMinimumHeight(20);

    //imageLabel = new QLabel(this);

	// ~ Modified by LEE jeun jeun@wayne-inc.com
    QPixmap pixmap("icon.png");
	imageLabel->setPixmap(pixmap.scaled(21, 20, Qt::IgnoreAspectRatio));
	// Modified by LEE jeun jeun@wayne-inc.com ~

    imageLabel->setMask(pixmap.mask());
    imageLabel->setScaledContents(true);
    imageLabel->setMinimumHeight(20);

    QLabel* label = new QLabel(this);
	// ~ Modified by LEE jeun jeun@wayne-inc.com
    label->setText("  Wayne Inc. OS Install Program 1.2.0");
    parent->setWindowTitle("  Wayne Inc. OS Install Program 1.2.0");
	// Modified by LEE jeun jeun@wayne-inc.com ~

    QHBoxLayout* hbox = new QHBoxLayout(this);
    hbox->addWidget(imageLabel);
    hbox->addWidget(label);
    hbox->addWidget(minimize);
    hbox->addWidget(close);

    hbox->insertStretch(2, 500);
    hbox->setSpacing(0);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    maxNormal = false;

    connect(close, SIGNAL( clicked() ), parent, SLOT(close() ) );
    connect(minimize, SIGNAL( clicked() ), this, SLOT(showSmall() ) );

}
TitleBar::~TitleBar()
{

    delete minimize;
    delete close;
    delete imageLabel;
}

void TitleBar::showSmall()
{
    parentWidget()->showMinimized();
}

void TitleBar::showMaxRestore()
{
    if (maxNormal) {
        parentWidget()->showNormal();
        maxNormal = !maxNormal;

    } else {
        parentWidget()->showMaximized();
        maxNormal = !maxNormal;

    }
}

void TitleBar::mousePressEvent(QMouseEvent *me)
{
    startPos = me->globalPos();
    clickPos = mapToParent(me->pos());
}
void TitleBar::mouseMoveEvent(QMouseEvent *me)
{
    if (maxNormal)
        return;
    parentWidget()->move(me->globalPos() - clickPos);
}
