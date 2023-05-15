#ifndef FKEY_H
#define FKEY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QSvgWidget>
#include <QGraphicsWidget>
#include <QGraphicsSvgItem>
#include <QGraphicsPixmapItem>
#include <QSvgRenderer>
#include <QString>

#include <QGraphicsProxyWidget>

/*
 * FKey - базовый класс
 * FTrebleClef - скрипичный ключ
 * FBassClef - басовый ключ
*/

class FKey :  public QGraphicsProxyWidget
{
protected:
    QSvgWidget * key;

public:
    FKey(QGraphicsItem * parent);
    ~FKey();
};

class FTrebleClef : public FKey
{   
public:
    FTrebleClef(QGraphicsItem * parent);
    ~FTrebleClef();
};

class FBassClef : public FKey
{
public:
    FBassClef(QGraphicsItem * parent);
    ~FBassClef();
};

#endif // FKEY_H
