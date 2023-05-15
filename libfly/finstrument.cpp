#include "finstrument.h"

#include <iostream>

FInstrument::FInstrument(QGraphicsItem * parentIt, int count)
    : QGraphicsWidget{parentIt}, countLines{count}
{
    for (int i = 0; i < countLines; i++)
    {
        addLines();
        if (i % 2 == 0)
            lines[i]->setDigitalInfAboutMusNote(44);
        else
            lines[i]->setDigitalInfAboutMusNote(32);
    }
    insth = refresh();
}

FInstrument::~FInstrument()
{
    foreach (auto &line, lines) {
        delete line;
    }
}

void FInstrument::addInfAboutLenNote(int len)
{
    foreach (auto &line, lines) {
        line->setLen(len);
    }
}

void FInstrument::addOrDelInfAboutKey(int x)
{
    int strCount = 1;
    foreach (auto &line, lines) {
        if (x == 0 && line->getKey() == nullptr)
            line->addKey(strCount);
        //else if (x != 0 && line->getKey() != nullptr)
        //    line->delKey();
        strCount++;
    }
}

void FInstrument::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (countLines < 2)
        return;
    painter->setPen(Qt::black);
    painter->drawLine(lines.first()->x(),\
                      lines.first()->y() + lines.first()->gettoplines(),\
                      lines.first()->x(),\
                      (lines.last())->y() + (lines.last())->getbottomlines());

    painter->drawLine(lines.first()->x() + lines.first()->getWidth(), \
                      lines.first()->y() + lines.first()->gettoplines(), \
                      lines.last()->x() + lines.last()->getWidth(), \
                      lines.last()->y() + lines.last()->getbottomlines());
}

QRectF FInstrument::boundingRect() const
{
    return QRectF(0, 0, lines.first()->getWidth(), insth);
}


void FInstrument::addLines()
{
    FLines *tmp = new FLines(this);
    QThread * th = new QThread;
    connect(th, &QThread::started, tmp, &FLines::run);
    lines << tmp;
    thread << th;
}

int FInstrument::refresh()
{
    int h = 0;
    foreach (auto &line, lines) {
        line->setPos(0, h);
        h += line->getHeight();
    }
    return h;
}

void FInstrument::run()
{
    foreach (auto &thrd, thread) {
        thrd->start();
    }
}

int FInstrument::getCountLines() const
{
    return countLines;
}

int FInstrument::getHeight() const
{
    return insth;
}
