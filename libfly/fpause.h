#ifndef FPAUSE_H
#define FPAUSE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QSvgWidget>

#include "felement.h"

class FPause : public QGraphicsProxyWidget, public FElement
{
protected:
    QSvgWidget * pause;

public:
    explicit FPause(QGraphicsItem * parent);
    virtual ~FPause();
};

class FWholePause : public FPause
{
public:
    explicit FWholePause(QGraphicsItem * parent);
    virtual ~FWholePause();
};

class FHalfPause : public FPause
{
public:
    explicit FHalfPause(QGraphicsItem * parent);
    virtual ~FHalfPause();
};

class FQuarterPause : public FPause
{
public:
    explicit FQuarterPause(QGraphicsItem * parent);
    virtual ~FQuarterPause();
};

class FEightPause : public FPause
{
public:
    explicit FEightPause(QGraphicsItem * parent);
    virtual ~FEightPause();
};

#endif // FPAUSE_H
