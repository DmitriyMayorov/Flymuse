#ifndef VNOTEPAPER_H
#define VNOTEPAPER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPoint>

#include "../libfly/ftakt.h"

class VNotePaperScene;

class VNotePaper : public QGraphicsView
{
    Q_OBJECT

    enum {
        AbsLineY = 6,
        width_of_sheet = 1000,
        height_of_sheet = 1200,
        width_of_lines = 800,
        height_of_lines = 100,
    };

    int inter_x,inter_y, last_inx, last_iny;

public:
    explicit VNotePaper(QWidget * parentw = nullptr);
    ~VNotePaper();

    void drawLine();
    QPoint getMouseCord(int pos_x, int pos_y);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    int ind;
    int length_next_note;

    VNotePaperScene * scene;

signals:
    void on_press_for_add_note(QPoint *point, int len);

public slots:
    void get_len_next_note(int length);
};


class VNotePaperScene : public QGraphicsScene
{
    Q_OBJECT

    FTakt * test;

public:

    VNotePaperScene(QObject *parent = nullptr, int w = 0, int h = 0);
    ~VNotePaperScene();

};

#endif // VNOTEPAPER_H
