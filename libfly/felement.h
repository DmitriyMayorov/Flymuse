#ifndef FELEMENT_H
#define FELEMENT_H


class FElement
{
protected:
    int x, y, museValue, lenMuse;
    bool isNote;
public:
    FElement(int _x, int _y);
    virtual ~FElement();

    friend bool operator==(const FElement &first, const FElement &second);

    void setx(int _x);
    void sety(int _y);

    int getx() const;
    int gety() const;
    int getMuse() const;
    bool getInfIsNote() const;
};

#endif // FELEMENT_H
