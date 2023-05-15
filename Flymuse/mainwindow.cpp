#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QScreen* screen = QApplication::screens().at(0);
    QSize sizeofscreen = screen->availableSize();

    this->resize(sizeofscreen.width(), sizeofscreen.height() - 70);//Какая-то погрешность и размер улетает за экран

    QGuiApplication::screens();

    razd = new QSplitter(Qt::Vertical, this);
    //razd->setHandleWidth(4);
    //razd->setStyleSheet("QSplitter::handle {background-color : white}");

    buttons = new MusWidgets(this);
    notecomp = new ViewPaper(this);

    //razd->addWidget(notecomp);
    razd->addWidget(buttons);
    razd->addWidget(notecomp);
    razd->move(0, ui->menubar->height());
    razd->resize(this->width(), this->height() - ui->menubar->height());
    //buttons->resize(this->width()/8, this->height() - ui->menubar->height());
    //notecomp->resize(this->width()/8*7, this->height() - ui->menubar->height());

    connect(ui->actionCreate, SIGNAL(triggered()), this, SLOT(SetSetting()));
    //connect(FVirtualNotePaper::, );

    //Connect для нот
    connect(buttons, &MusWidgets::FirstButtonSignal, notecomp, &ViewPaper::FirstButtonSlot);
    connect(buttons, &MusWidgets::SecondButtonSignal, notecomp, &ViewPaper::SecondButtonSlot);
    connect(buttons, &MusWidgets::ThirdButtonSignal, notecomp, &ViewPaper::ThirdButtonSlot);
    connect(buttons, &MusWidgets::ThoughtButtonSignal, notecomp, &ViewPaper::ThoughtButtonSlot);
    connect(buttons, &MusWidgets::PlayButtonSignal, notecomp, &ViewPaper::PlayButtonSlot);
}

MainWindow::~MainWindow()
{
    delete buttons;
    delete notecomp;
    delete razd;
    delete ui;
}

void MainWindow::SetSetting()
{
    auto settings = new Create();
    settings->show();
}

void MainWindow::SetSave()
{

}
