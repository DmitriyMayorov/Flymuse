#include "ftakt.h"

#include <iostream>


FTakt::FTakt(QGraphicsItem * parentIt)
    : QGraphicsWidget{parentIt}
{
    this->addInstrument(2);
    _h = refresh();
}

FTakt::~FTakt()
{
    qDeleteAll(instr);
}

void FTakt::addInfAboutLenNote(int len)
{
    foreach (auto &inst, instr) {
        inst->addInfAboutLenNote(len);
    }
}

void FTakt::run()
{
    foreach (auto &inst, instr) {
        inst->run();
    }
}

void FTakt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::black);
}

QRectF FTakt::boundingRect() const
{
    return QRectF(0, 0, _w, _h);
}

void FTakt::addInstrument(int countlines)
{
    FInstrument * tmp = new FInstrument(this, countlines);
    instr << tmp;
}

void FTakt::addOrDelInfAboutKey(int x)
{
    foreach (auto &inst, instr) {
        inst->addOrDelInfAboutKey(x);
    }
}

int FTakt::refresh()
{
    int h = 0;
    foreach (auto &inst, instr) {
        inst->setPos(0, h);
        h += inst->getHeight();
    }
    return h;
}

int FTakt::getWidth() const
{
    return _w;
}

int FTakt::getHeight() const
{
    return _h;
}
