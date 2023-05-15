#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QScrollArea>
#include <QDesktopWidget>
#include <QScreen>

#include <muswidgets.h>
#include <viewpaper.h>
#include <../DialogWindows/create.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*
Окно занимает всё пространсто и содержит три области:
    1. Область показа нотных листов
    2. Область возможностей, применимых к нотному листу
    3. Область верхнего меню, в котором есть возможность создания параметров нового файл.
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSplitter * razd;
    MusWidgets * buttons;
    ViewPaper * notecomp;

    Ui::MainWindow *ui;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void SetSetting();
    void SetSave();
};


#endif // MAINWINDOW_H
