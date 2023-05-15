#include "fnotes.h"

FNote::FNote(QGraphicsItem * parentIt, int x, int y)
    : QGraphicsWidget{parentIt} , FElement(x, y)
{
    lenMuse = 32;
    isNote = true;
}

FNote::~FNote()
{

}


void FNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->getx(), this->gety(), 10, 10);
    //painter->drawLine(this->getx() + 10, this->gety() + 5, this->getx() + 10, this->gety() + 5 - 27);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF FNote::boundingRect() const
{
    return QRectF(this->getx(), this->gety() - 25, this->getx() + 20, this->gety() + 10);
}


FPNote::FPNote(QGraphicsItem * parentIt , int x, int y)
    : FNote(parentIt, x, y)
{
    lenMuse = 16;
    isNote = true;
}

FPNote::~FPNote()
{

}

void FPNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->getx(), this->gety(), 10, 10);
    painter->drawLine(this->getx() + 10, this->gety() + 5, this->getx() + 10, this->gety() + 5 - 27);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

FQNote::FQNote(QGraphicsItem * parentIt ,int x, int y)
    : FNote(parentIt, x, y)
{
    lenMuse = 8;
    isNote = true;
}

FQNote::~FQNote()
{

}

void FQNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->getx(), this->gety(), 10, 10);
    painter->drawLine(this->getx() + 10, this->gety() + 5, this->getx() + 10, this->gety() + 5 - 27);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

FENote::FENote(QGraphicsItem * parentIt ,int x, int y)
    : FNote(parentIt, x, y)
{
    lenMuse = 4;
    isNote = true;
    path = new QPainterPath();
}

FENote::~FENote()
{
    delete path;
}

void FENote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->getx(), this->gety(), 10, 10);
    painter->drawLine(this->getx() + 10, this->gety() + 5, this->getx() + 10, this->gety() + 5 - 27);

    //сплайн
    path->moveTo(this->getx() + 10, this->gety() + 5 - 27);
    path->cubicTo(this->getx() + 10 + 3, this->gety() + 5 - 17,this->getx() + 10 + 6, this->gety() + 5 - 20,this->getx() + 10 + 10, this->gety() + 5 - 13);

    painter->drawPath(*path);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

FSNote::FSNote(QGraphicsItem * parentIt , int x, int y)
    : FNote(parentIt , x, y)
{
    lenMuse = 2;
    isNote = true;
    fpath = new QPainterPath();
    spath = new QPainterPath();
}

FSNote::~FSNote()
{
    delete fpath;
    delete spath;
}

void FSNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->getx(), this->gety(), 10, 10);
    painter->drawLine(this->getx() + 10, this->gety() + 5, this->getx() + 10, this->gety() + 5 - 27);

    fpath->moveTo(this->getx() + 10, this->gety() + 5 - 27);
    fpath->cubicTo(this->getx() + 10 + 3, this->gety() + 5 - 17,this->getx() + 10 + 6, this->gety() + 5 - 20,this->getx() + 10 + 10, this->gety() + 5 - 13);
    spath->moveTo(this->getx() + 10, this->gety() + 5 - 27 + 5);
    spath->cubicTo(this->getx() + 10 + 3, this->gety() + 5 - 17 + 5,this->getx() + 10 + 6, this->gety() + 5 - 20 + 5,this->getx() + 10 + 10, this->gety() + 5 - 13 + 5);

    painter->drawPath(*spath);
    painter->drawPath(*fpath);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
