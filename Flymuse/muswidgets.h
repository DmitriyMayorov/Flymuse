#ifndef MUSWIDGETS_H
#define MUSWIDGETS_H

#include <QGroupBox>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#include <cmath>

namespace Ui {
class MusWidgets;
}

class MusWidgets : public QGroupBox
{
    Q_OBJECT

    Ui::MusWidgets *ui;

public:
    explicit MusWidgets(QWidget *parent = nullptr);
    ~MusWidgets();

signals:
    void FirstButtonSignal();
    void SecondButtonSignal();
    void ThirdButtonSignal();
    void ThoughtButtonSignal();
    void PlayButtonSignal();

private slots:
    void on_First_clicked();
    void on_Second_clicked();
    void on_Third_clicked();
    void on_Thought_clicked();
    void on_Play_clicked();
};

#endif // MUSWIDGETS_H
