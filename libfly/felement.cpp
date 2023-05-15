#include "felement.h"

FElement::FElement(int _x, int _y)
    : x{_x}, y{_y}
{

}

FElement::~FElement()
{

}

bool operator==(const FElement &first, const FElement &second)
{
    return ((first.getInfIsNote() == second.getInfIsNote()) && \
            (first.getx() == second.getx()) && \
            first.gety() == second.gety() && \
            first.getMuse() == second.getMuse());
}

void FElement::setx(int _x)
{
    x = _x;
}

void FElement::sety(int _y)
{
    y = _y;
}

int FElement::getx() const
{
    return x;
}

int FElement::gety() const
{
    return y;
}

int FElement::getMuse() const
{
    return lenMuse;
}

bool FElement::getInfIsNote() const
{
    return isNote;
}
