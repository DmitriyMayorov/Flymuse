#ifndef FVIRTUALNOTEPAPER_H
#define FVIRTUALNOTEPAPER_H

#include <QObject>
#include <QGraphicsWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QList>
#include <QGraphicsLinearLayout>

#include "ftakt.h"

//class FVirtualNotePaperScene;
class FVirtualNoteViewTakts;

class FVirtualNotePaper : public QGraphicsWidget
{
    Q_OBJECT
    FVirtualNoteViewTakts * ViewTakts;

    enum {
        width_of_sheet = 1000,
        height_of_sheet = 1200,
    };

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    FVirtualNotePaper(QGraphicsItem * parent = nullptr);
    ~FVirtualNotePaper();
    //void mousePressEvent(QGraphicsSceneMouseEvent * event);  

    FVirtualNoteViewTakts* getPlaceOfViewNote() const;
    int getWidth() const;
    int getHeight() const;

};

class FVirtualNoteViewTakts : public QGraphicsWidget
{
    Q_OBJECT

    int count = 16;

    QList<FTakt *> takts;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    FVirtualNoteViewTakts(QGraphicsItem * parent,int x, int y, int w, int h);
    ~FVirtualNoteViewTakts();

    void addInfAboutLenNote(int len);
    void run();

    void addTatk();
    void updateTakts();
    bool isWidgetTakts(int taktH, QPoint point); // Перенести потом в protected, поскольку функция не вызывается напрямую.
    bool isWidgetLineTakts(int taktW, QPoint point);//Смотри выше. Тоже самое.
/*
protected slots:
    void sendingTakts();
*/
};
#endif // FVIRTUALNOTEPAPER_H
