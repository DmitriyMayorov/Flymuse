#ifndef FINSTRUMENT_H
#define FINSTRUMENT_H

#include <QObject>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QPainter>
#include <QPainterPath>
#include <QList>
#include <QThread>

#include "flines.h"

class FInstrument : public QGraphicsWidget
{
    Q_OBJECT

    int countLines, insth;
    bool Debug = true;

    QList<QThread *> thread;
    QList<FLines *> lines;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
    QRectF boundingRect() const override;

public:
    explicit FInstrument(QGraphicsItem * parentIt, int count);
    virtual ~FInstrument();

    void addInfAboutLenNote(int len);
    void addOrDelInfAboutKey(int x);

    void addLines();
    int refresh();
    void run();

    /*----Функции получения значений----*/

    int getCountLines() const;
    int getHeight() const;
};

#endif // FINSTRUMENT_H
