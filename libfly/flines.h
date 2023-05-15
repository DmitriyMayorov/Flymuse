#ifndef FLINES_H
#define FLINES_H

#include <QObject>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QPainter>
#include <QList>
#include <QStack>
#include <QGraphicsSceneMouseEvent>
#include <QSvgRenderer>

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>

#include <algorithm>

#include "fkey.h"
#include "fpause.h"
#include "fnotes.h"

class FLines : public QGraphicsProxyWidget
{
    Q_OBJECT

    enum {
        _w = 200,
        _h = 100,
        _step = 10,
    };

    QMediaPlayer * player;
    QAudioOutput * audioOutput;
    QTimer * timer;

    FKey * key = nullptr;

    QList<FElement*> notes;
    QStack<FPause *> temp;

    /*
     * lenNote - вид нот, который должен отрисовываться на экране
     * lenLineTakt - временная величина такта. Измеряется в 128(для начала в 32)-ых, т.е в максимально минимальном размере, сипользуемом в музыке
     * Также будет создана функция, которая будет подсчитывать временную часть такта, часть которой заполнена нотами и на основании этой информации отрисовывать паузы,
     * приэтом минимизировав их количество.
    */
    int _x, _y, _st, lenNote = 0, lenLineTakt = 32, DigitalAboutMuseNote = -1000;
    bool isActiveTimerMediaPlayer = false;

private slots:
    void timeOutMediaPlayerSlot();

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

public:
    //деструктор и конструктор
    explicit FLines(QGraphicsItem * parentIt = nullptr, int x = 0, int y = 0);
    virtual ~FLines();
    //Добавление ключа и его удаление - удаление не нужно пока что
    void addKey(int strCount);
    void delKey();
    //Добавление ноты и установка длительности данной ноты
    void addNote(int x, int y);
    void setLen(int len);
    //проигрвыние
    void playNote(int y, int time);
    void run();

    //Переотрисовка пауз при добавлении ноты + функции, которые нужны для переотрисовки
    void refreshNote(FNote * note);
    /*
     * getIndexPosition - нахождение номера элемента в односвязном списке
     * CreateStackPauses - создание пауз и занесение их в специальный промежуточный стек
     * DeleteStackPauses - удаление и стека и перемещение всех пауз на поле
     * setDigitalInfAboutMusNote - изменение информации о индексе звука
     */
    int getIndexPosition(FElement * el);
    int CreateStackPauses(int value);
    int DeleteStackPauses(int stx, int lx, int count);
    void setDigitalInfAboutMusNote(int DI);

    //Выстраивание сетки координат. Получение координат по сетке
    QPoint correctCord(int x, int y);

    int getHeight() const;
    int getWidth() const;
    int gettoplines() const;
    int getabslines() const;
    int getbottomlines() const;
    QPoint getStartPoint() const;
    FKey *getKey() const;
};

#endif // FLINES_H
