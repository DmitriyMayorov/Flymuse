#include "flines.h"

#include <iostream>
#include <unistd.h>

//функция-правило сортировки
//--------------------------------------------------------------
bool ElementLessThan(const FElement *v1, const FElement *v2)
{
    return v1->getx() < v2->getx();
}
//--------------------------------------------------------------


FLines::FLines(QGraphicsItem *parentIt, int x, int y)
    : QGraphicsProxyWidget{parentIt}, _x{x}, _y{y}
{
    _st = (_h - _step * 4) / 2;
    this->setAcceptHoverEvents(true);
    this->setMinimumSize(_w, _h);

    player = new QMediaPlayer;
    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChan));

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &FLines::timeOutMediaPlayerSlot);

    refreshNote(nullptr);
}

FLines::~FLines()
{
    qDeleteAll(notes);
}

void FLines::addKey(int strCount)
{
    if (strCount % 2 == 0)
    {
        key = new FBassClef(this);
        key->setPos(0, _h/2 - 30);
    }
    else
    {
        key = new FTrebleClef(this);
        key->setPos(0, _h/2 - 24);
    }
    //key->setPos(0, _h/2);
    //key->show();
}

void FLines::delKey()
{
    if (key != nullptr)
        delete key;
}

void FLines::timeOutMediaPlayerSlot()
{
    player->stop();
    isActiveTimerMediaPlayer = false;
    timer->stop();
}

void FLines::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);
    for(int i = 0; i < 5; i++)
        painter->drawLine(_x, _st + _step * i, _x + _w, _st + _step * i);

    //painter->setBrush(Qt::blue);
    //painter->drawRect(0, 0, this->size().width(), this->size().height());
    painter->drawLine(0, _st, 0, _st + (_step * 4));
    painter->drawLine(_w, _st, _w, _st + (_step * 4));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void FLines::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPoint CorrPoint = correctCord(event->pos().x(), event->pos().y());
    addNote(CorrPoint.x(), CorrPoint.y());
}

//Как отследить перемещение мыши по объекту QGraphicsWidget?

void FLines::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << event->pos().x() << "------" << std::endl;
}

QRectF FLines::boundingRect() const
{
    return QRectF(0, 0, _w, _h);
}

QPoint FLines::correctCord(int x, int y)
{
    y -= 2;
    for (int i = getStartPoint().y(); i <= _h; i += _step/2)
    {
        if (y >= i && y < i + _step/2)
            return QPoint(x, i);//Всё таки есть погрешость
    }
    return QPoint(-1, -1);
}

int FLines::getHeight() const
{
    return _h;
}

int FLines::getWidth() const
{
    return _w;
}

int FLines::getbottomlines() const
{
    return _st + _step * 4;
}

int FLines::getabslines() const
{
    return _step;
}

int FLines::gettoplines() const
{
    return _st;
}

QPoint FLines::getStartPoint() const
{
    int yst = _st - ((_st / _step) * _step);
    if ((yst - _step/2) >= 0)
        return QPoint(0, yst - _step/2);
    else
        return QPoint(0, yst);
}

FKey *FLines::getKey() const
{
    return key;
}

void FLines::addNote(int x, int y)
{
    FNote * tmp;
    switch (lenNote) {
        case 1:
            tmp = new FNote(this, x, y);
            break;
        case 2:
            tmp = new FPNote(this, x, y);
            break;
        case 4:
            tmp = new FQNote(this, x, y);
            break;
        case 8:
            tmp = new FENote(this, x, y);
            break;
        default:
            break;
    }
    notes << tmp;
    std::sort(notes.begin(), notes.end(), ElementLessThan);
    playNote(y, 1000);
    refreshNote(tmp);
}

void FLines::setLen(int len)
{
    lenNote = len;
}

void FLines::playNote(int y, int time)
{
    int startY = gettoplines();
    int DigitalInfAboutNote = DigitalAboutMuseNote;//32 - 44
    while (std::abs(startY - y) != 0)
    {
        if (startY > y)
        {
            startY -= _step/2;
            DigitalInfAboutNote++;
        }
        else
        {
            startY += _step/2;
            DigitalInfAboutNote--;
        }
    }

    QString filename = "";
    QString path = "/home/dmitriy/Qt/Flymuse/Piano/";

    switch (DigitalInfAboutNote % 7) {
    case 0:
        filename.append(QString("C"));
        break;
    case 1:
        filename.append(QString("D"));
        break;
    case 2:
        filename.append(QString("E"));
        break;
    case 3:
        filename.append(QString("F"));
        break;
    case 4:
        filename.append(QString("G"));
        break;
    case 5:
        filename.append(QString("A"));
        break;
    case 6:
        filename.append(QString("B"));
        break;
    default:
        break;
    }

    filename.append(QString::number((DigitalInfAboutNote/7) % 7));
    filename.append(QString("_flkeys.wav"));
    path.append(filename);
    player->setMedia(QUrl::fromLocalFile(path));
    player->play();
    isActiveTimerMediaPlayer = true;
    timer->start(time);
}

void FLines::run()
{
    int WholeValue = 1000;
    foreach (auto el, notes) {
        if (el->getInfIsNote())
        {
            playNote(el->gety(), (WholeValue * el->getMuse())/32);
        }
        else
            sleep((WholeValue * el->getMuse()) / 32000);
    }
}

void FLines::refreshNote(FNote * note)
{
    if (notes.length() == 0 && note == nullptr)
    {
        int museValueSt = 32;
        int StCountSt = CreateStackPauses(museValueSt);
        DeleteStackPauses(0, getWidth(), StCountSt + 1);
        return;
    }
    int ind = getIndexPosition(note);
    if (ind == -1)
        return;
    ind++;
    int museValue = 0, lastx = getWidth(); 
    FElement * tel;
    while (ind < notes.length())
    {
        if (!notes[ind]->getInfIsNote())
        {
            museValue += notes[ind]->getMuse();
            tel = notes.takeAt(ind);
            static_cast<FPause*>(tel)->hide();
            delete tel;
        }
        else
        {
            lastx = notes[ind]->getx();
            break;
        }
        ind++;
    }
    if (ind == 1 && notes.length() == 1)
        museValue = 32;
    museValue -= note->getMuse();
    int StCount = CreateStackPauses(museValue);
    DeleteStackPauses(note->getx(), lastx, StCount);
    /*
     * 1. Функция создания стека под паузы. НАДО ПОПРОБОВАТЬ ИСПОЛЬЗОВАТЬ QStack
     * 2. Функция выброса пауз на ноты (выгрузка) с последующим удалением стека.
    */
}

int FLines::getIndexPosition(FElement *el)
{
    int ind = -1;
    for (int i = 0; i < notes.length(); i++)
    {
        if (*(notes[i]) == *el)
        {
            ind = i;
            return ind;
        }
    }

    return ind;
}

int FLines::CreateStackPauses(int value)
{
    int countSt = 0;

    if (value <= 0)
        return countSt;

    int minelr = 32;

    while (value < minelr)
        minelr /= 2;

    while (value != 0)
    {
        countSt++;
        switch (minelr) {
        case 32:
            temp.push(new FWholePause(this));
            break;
        case 16:
            temp.push(new FHalfPause(this));
            break;
        case 8:
            temp.push(new FQuarterPause(this));
            break;
        case 4:
            temp.push(new FEightPause(this));
            break;
        default:
            break;
        }
        value -= minelr;
        minelr /= 2;
    }
    return countSt;
}

int FLines::DeleteStackPauses(int stx, int lx, int count)
{
    if (count == 0)
        return -1;

    int dx = (lx - stx) / count;
    FPause * TempPause;

    while (!temp.empty())
    {
        TempPause = temp.pop();
        switch (TempPause->getMuse()) {
        case 32:
            TempPause->setPos(stx + dx - 20, _h/2 - 18);
            TempPause->setx(stx + dx - 20);
            TempPause->sety(_h/2 - 20);
            break;
        case 16:
            TempPause->setPos(stx + dx - 20,_h/2 - 14);
            TempPause->setx(stx + dx - 20);
            TempPause->sety(_h/2 - 20);
            break;
        case 8:
            TempPause->setPos(stx + dx - 20,_h/2 - 20);
            TempPause->setx(stx + dx - 20);
            TempPause->sety(_h/2 - 20);
            break;
        case 4:
            TempPause->setPos(stx + dx - 20,_h/2 - 16);
            TempPause->setx(stx + dx - 20);
            TempPause->sety(_h/2 - 20);
            break;
        default:
            break;
        }
        notes << TempPause;
        stx += dx;
    }

    std::sort(notes.begin(), notes.end(), ElementLessThan);
    return 0;
}

void FLines::setDigitalInfAboutMusNote(int DI)
{
    DigitalAboutMuseNote = DI;
}
