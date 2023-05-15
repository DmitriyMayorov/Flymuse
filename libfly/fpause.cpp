#include "fpause.h"

FPause::FPause(QGraphicsItem * parent)
    : QGraphicsProxyWidget(parent), FElement(0, 0)
{
    isNote = false;
}

FPause::~FPause()
{
    //delete pause;
}

FWholePause::FWholePause(QGraphicsItem *parent)
    : FPause(parent)
{
    isNote = false;
    lenMuse = 32;
    pause = new QSvgWidget(QString("/home/dmitriy/Qt/Flymuse/Picture/1.1.svg"));
    this->setWidget(pause);
    pause->resize(20, 20);
    pause->setAttribute(Qt::WA_NoSystemBackground);
}

FWholePause::~FWholePause()
{
    //delete pause;
}

FHalfPause::FHalfPause(QGraphicsItem *parent)
    : FPause(parent)
{
    isNote = false;
    lenMuse = 16;
    pause = new QSvgWidget(QString("/home/dmitriy/Qt/Flymuse/Picture/1.2.svg"));
    this->setWidget(pause);
    pause->resize(20, 20);
    pause->setAttribute(Qt::WA_NoSystemBackground);
}

FHalfPause::~FHalfPause()
{

}

FQuarterPause::FQuarterPause(QGraphicsItem *parent)
     : FPause(parent)
{
    isNote = false;
    lenMuse = 8;
    pause = new QSvgWidget(QString("/home/dmitriy/Qt/Flymuse/Picture/1.4.svg"));
    this->setWidget(pause);
    pause->resize(20, 30);
    pause->setAttribute(Qt::WA_NoSystemBackground);
}

FQuarterPause::~FQuarterPause()
{
    //delete pause;
}

FEightPause::FEightPause(QGraphicsItem *parent)
     : FPause(parent)
{
    lenMuse = 4;
    isNote = false;
    pause = new QSvgWidget(QString("/home/dmitriy/Qt/Flymuse/Picture/1.8.svg"));
    this->setWidget(pause);
    pause->resize(20, 20);
    pause->setAttribute(Qt::WA_NoSystemBackground);
}

FEightPause::~FEightPause()
{
    //delete pause;
}
