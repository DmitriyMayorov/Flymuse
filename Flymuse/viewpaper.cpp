#include "viewpaper.h"
//#include <iostream>
/*
 Задание - реалзация возможности перемещения по задержке и нажтию и перемещению мыши перемещать нотные листы
 И, БЛИН, НАДО РАЗОБРАТЬСЯ С БАГОМ В FLINES. ЭТО ПРОСТО ЖЕСТЬ НЕПОНЯТНАЯ
*/
ViewPaper::ViewPaper(QWidget *parent)
    : QGraphicsView{parent}
{
    //setMouseTracking(true);
    scene = new ScenePaper(this);
    this->setScene(scene);
    scene->setSceneRect(0, 0, this->width(), this->height());
    this->setStyleSheet("background-color: gray");
}

ViewPaper::~ViewPaper()
{
    delete scene;
}

ScenePaper *ViewPaper::getScenePaper() const
{
    return scene;
}

void ViewPaper::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        this->getScenePaper()->addInfAboutLenNote(0);
        break;
    default:
        break;
    }
}

void ViewPaper::FirstButtonSlot()
{
    this->getScenePaper()->addInfAboutLenNote(1);
}

void ViewPaper::SecondButtonSlot()
{
    this->getScenePaper()->addInfAboutLenNote(2);
}

void ViewPaper::ThirdButtonSlot()
{
    this->getScenePaper()->addInfAboutLenNote(4);
}

void ViewPaper::ThoughtButtonSlot()
{
    this->getScenePaper()->addInfAboutLenNote(8);
}

void ViewPaper::PlayButtonSlot()
{
    this->getScenePaper()->run();
}

/*
void ViewPaper::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    if (event->button() == Qt::LeftButton)
    {
        userVX = event->x();
        userVY = event->y();
    }
}

void ViewPaper::mouseMoveEvent(QMouseEvent *event)
{

    if (event->buttons() & Qt::LeftButton)
    {
        QPointF oldp = mapToScene(userVX, userVY);
        QPointF newp = mapToScene(event->pos());
        QPointF trans = newp - oldp;
        translate(trans.x(), trans.y());
        userVX = event->x();
        userVY = event->y();
    }
    if (event->buttons() == Qt::LeftButton)
    {
        setTransformationAnchor(QGraphicsView::NoAnchor);
        translate(event->x(), event->y());
        this->scene->update();
    }
}*/

ScenePaper::ScenePaper(QObject *parent)
    : QGraphicsScene{parent}
{
    this->addVirtualPaper();
    //this->temp = new FBassClef("/home/dmitriy/Qt/Flymuse/Picture/BassKey.svg", nullptr);
    //this->addItem(temp);
    //temp->setPos(100, 100);
    //tmp->show();
}

ScenePaper::~ScenePaper()
{
    qDeleteAll(virtualpapers);
}

void ScenePaper::addInfAboutLenNote(int len)
{
    foreach (auto &virtualpaper, virtualpapers) {
        virtualpaper->getPlaceOfViewNote()->addInfAboutLenNote(len);
    }
}

void ScenePaper::addVirtualPaper()
{
    FVirtualNotePaper *tmp = new FVirtualNotePaper;
    this->addItem(tmp);
    virtualpapers << tmp;
    this->redraw();
}

void ScenePaper::redraw()
{
    //Как это работает????? Подогнал под картинку и не понимаю!!!!

    //std::cout << this->width() << "\t" <<this->height() << std::endl;
    int x = this->width()/10 - this->virtualpapers.first()->getWidth()/2, y = -500; //Фантастическая хернь
    foreach (auto& vnp, virtualpapers) {
        vnp->setPos(x, y);
        x += vnp->getWidth() + 50; // 50 - разделитель между нотными листами
    }
}

void ScenePaper::run()
{
    foreach (auto &virtualpaper, virtualpapers) {
        virtualpaper->getPlaceOfViewNote()->run();
    }
}
