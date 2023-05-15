#ifndef VIEWPAPER_H
#define VIEWPAPER_H


#include <QList>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLinearLayout>


#include "../libfly/fkey.h"
#include "../libfly/fvirtualnotepaper.h"

//Место для показа нотных листов

class ScenePaper;

class ViewPaper : public QGraphicsView
{
    Q_OBJECT

    ScenePaper * scene;
    int userVX, userVY;

public:
    ViewPaper(QWidget * parent = nullptr);
    ~ViewPaper();

    ScenePaper* getScenePaper() const;

protected:
    void keyPressEvent(QKeyEvent * event) override;

public slots:
    void FirstButtonSlot();
    void SecondButtonSlot();
    void ThirdButtonSlot();
    void ThoughtButtonSlot();
    void PlayButtonSlot();
};

class ScenePaper: public QGraphicsScene
{
    Q_OBJECT

    //FBassClef * temp;
    QList<FVirtualNotePaper *> virtualpapers;
    QGraphicsLinearLayout * layout;

public:
    explicit ScenePaper(QObject *parent = nullptr);
    ~ScenePaper();

    void addInfAboutLenNote(int len);
    void addVirtualPaper();
    void redraw();
    void run();
};


#endif // VIEWPAPER_H
