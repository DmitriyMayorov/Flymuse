#ifndef FNOTES_H
#define FNOTES_H

#include <QObject>
#include <QGraphicsWidget>
#include <QPainter>
#include <QPainterPath>

#include "felement.h"

class FNote : public QGraphicsWidget, public FElement
{
    Q_OBJECT

    int notelen;


public:
    explicit FNote(QGraphicsItem * parentIt, int x, int y);
    virtual ~FNote(); // виртуальный деструктор класса предка для того, чтобы не происходило утечки памяти

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
    QRectF boundingRect() const override;

};

class FPNote : public FNote
{
public:
    explicit FPNote(QGraphicsItem * parentIt, int x, int y);
    virtual ~FPNote();

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
};

class FQNote : public FNote
{
public:
    explicit FQNote(QGraphicsItem * parentIt, int x, int y);
    virtual ~FQNote();

protected:
   virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
};

class FENote : public FNote
{

    QPainterPath * path;

public:
    explicit FENote(QGraphicsItem * parentIt , int x, int y);
    virtual ~FENote();

protected:
   virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
};

class FSNote : public FNote
{

    QPainterPath *fpath;
    QPainterPath *spath;

public:
    explicit FSNote(QGraphicsItem * parentIt , int x, int y);
    virtual ~FSNote();

protected:
   virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
};

#endif // FNOTES_H
