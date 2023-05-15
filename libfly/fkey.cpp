#include "fkey.h"

#include <iostream>

FKey::FKey(QGraphicsItem * parent)
    : QGraphicsProxyWidget(parent)
{

}

FKey::~FKey()
{
    //delete key;
}


FTrebleClef::FTrebleClef(QGraphicsItem *parent)
    : FKey(parent)
{
    key = new QSvgWidget(QString("/home/dmitriy/Qt/Flymuse/Picture/ScrKey.svg"));
    this->setWidget(key);
    key->resize(30, 50);
    key->setAttribute(Qt::WA_NoSystemBackground);
    //key->setStyleSheet("background-color: rdba(0, 0, 0, 90);");
}

FTrebleClef::~FTrebleClef()
{

}

FBassClef::FBassClef(QGraphicsItem *parent)
    : FKey(parent)
{
    key = new QSvgWidget(QString("/home/dmitriy/Qt/Flymuse/Picture/BassKey.svg"));
    this->setWidget(key);
    key->resize(40, 50);
    //key->setStyleSheet("background-color: white");
    key->setAttribute(Qt::WA_NoSystemBackground);
}

FBassClef::~FBassClef()
{

}
