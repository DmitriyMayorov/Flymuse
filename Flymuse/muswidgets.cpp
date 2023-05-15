#include "muswidgets.h"
#include "ui_muswidgets.h"

MusWidgets::MusWidgets(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::MusWidgets)
{
    ui->setupUi(this);

    ui->First->setStyleSheet("border-image: url(/home/dmitriy/Qt/Flymuse/Picture/First.png) stretch; ");
    ui->Second->setStyleSheet("border-image: url(/home/dmitriy/Qt/Flymuse/Picture/Second.png) stretch; ");
    ui->Third->setStyleSheet("border-image: url(/home/dmitriy/Qt/Flymuse/Picture/Third.png) stretch; ");
    ui->Thought->setStyleSheet("border-image: url(/home/dmitriy/Qt/Flymuse/Picture/Thought.png) stretch; ");
    ui->Play->setStyleSheet("border-image: url(/home/dmitriy/Qt/Flymuse/Picture/Run.png) stretch; ");

    this->setMaximumHeight(60);
    this->setMinimumHeight(60);
}

MusWidgets::~MusWidgets()
{
    delete ui;
}


void MusWidgets::on_First_clicked()
{
    emit FirstButtonSignal();
}


void MusWidgets::on_Second_clicked()
{
    emit SecondButtonSignal();
}


void MusWidgets::on_Third_clicked()
{
    emit ThirdButtonSignal();
}


void MusWidgets::on_Thought_clicked()
{
    emit ThoughtButtonSignal();
}


void MusWidgets::on_Play_clicked()
{
    emit PlayButtonSignal();
}

