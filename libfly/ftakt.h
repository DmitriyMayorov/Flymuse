#ifndef FTAKT_H
#define FTAKT_H

#include <QList>
#include <QObject>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QPainter>
#include <QPainterPath>

#include "finstrument.h"

class FTakt : public QGraphicsWidget
{
    Q_OBJECT

    int _w = 200, _h = 0;

    QList<FInstrument *> instr;
    QGraphicsLinearLayout * layout;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
    QRectF boundingRect() const override;
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:

    explicit FTakt(QGraphicsItem * parent = nullptr);
    ~FTakt();

    void addInfAboutLenNote(int len);
    void run();
    void addInstrument(int countlines);
    void addOrDelInfAboutKey(int x);
    int refresh();
    int getWidth() const;
    int getHeight() const;
};

#endif // FTAKT_H
