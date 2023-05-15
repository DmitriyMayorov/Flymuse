#include "fvirtualnotepaper.h"
#include <ciso646>
#include <iostream>

FVirtualNotePaper::FVirtualNotePaper(QGraphicsItem *parent)
    : QGraphicsWidget{parent}
{
    ViewTakts = new FVirtualNoteViewTakts(this, 100, 100, 800, 1000);
    this->setMaximumHeight(height_of_sheet);
    this->setMaximumWidth(width_of_sheet);
    this->setMinimumHeight(height_of_sheet);
    this->setMinimumWidth(width_of_sheet);
}

FVirtualNotePaper::~FVirtualNotePaper()
{
    delete ViewTakts;
}

FVirtualNoteViewTakts* FVirtualNotePaper::getPlaceOfViewNote() const
{
    return ViewTakts;
}

void FVirtualNotePaper::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::white);
    painter->drawRect(0, 0, width_of_sheet, height_of_sheet);
}

/*void FVirtualNotePaper::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     std::cout << event->scenePos().x()  << std::endl;
}*/

int FVirtualNotePaper::getWidth() const
{
    return width_of_sheet;
}

int FVirtualNotePaper::getHeight() const
{
    return height_of_sheet;
}

FVirtualNoteViewTakts::FVirtualNoteViewTakts(QGraphicsItem *parent, int x, int y, int w, int h)
    : QGraphicsWidget{parent}
{
    this->setGeometry(x, y, w, h);
    for(int i = 0; i < count; i++)
        this->addTatk();
}

FVirtualNoteViewTakts::~FVirtualNoteViewTakts()
{
    qDeleteAll(takts);
}

void FVirtualNoteViewTakts::addInfAboutLenNote(int len)
{
    foreach (auto &takt, takts) {
        takt->addInfAboutLenNote(len);
    }
}

void FVirtualNoteViewTakts::run()
{
    foreach (auto &takt, takts) {
        takt->run();
    }
}

void FVirtualNoteViewTakts::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
    //painter->setBrush(Qt::blue);
    //painter->drawRect(0, 0, this->geometry().width(), this->geometry().height());
}

/*void FVirtualNoteViewTakts::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     std::cout << event->scenePos().x()  << std::endl;
}*/


void FVirtualNoteViewTakts::addTatk()
{
    FTakt *tmp = new FTakt(this);
    takts << tmp;
    this->updateTakts();
}

void FVirtualNoteViewTakts::updateTakts()
{
    int x = 0, y = 0;
    foreach (auto& takt, takts) {
        //Здесь должна быть проверка на условие принадлежности такта к нотному листу или нотной тактовой полоске
        //std::cout << takt->size().width() << std::endl;
        if (!isWidgetLineTakts(takt->getWidth(), QPoint(x, y)))
        {
            //std::cout << takt->getHeight() << std::endl;
            y += takt->getHeight();/*Костыль с целочисленным делением на 2*/
            x = 0;
        }
        takt->setPos(x, y);
        takt->addOrDelInfAboutKey(x);
        x = takt->x() + takt->getWidth();
    }
}

bool FVirtualNoteViewTakts::isWidgetTakts(int taktH, QPoint point)
{
    //Провекра, хватает ли места такту на виртуальном нотном листе
    if (this->size().height() - point.y() < taktH)
        return false;
    return true;
}

bool FVirtualNoteViewTakts::isWidgetLineTakts(int taktW, QPoint point)
{
    //Проверка, может ли находится такт на одной "полоске"
    if (this->size().width() - point.x() < taktW)
        return false;
    return true;
}

