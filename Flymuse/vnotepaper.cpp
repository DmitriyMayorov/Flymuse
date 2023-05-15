#include <vnotepaper.h>


VNotePaper::VNotePaper(QWidget *parentw)
    : QGraphicsView{parentw}
{
    length_next_note = 0;

    setMouseTracking(true);

    this->setMaximumHeight(height_of_sheet);
    this->setMaximumWidth(width_of_sheet);
    this->setMinimumHeight(height_of_sheet);
    this->setMinimumWidth(width_of_sheet);

    this->setStyleSheet("background-color: white");

    scene = new VNotePaperScene(this, width_of_sheet, height_of_sheet);
    this->resize(width_of_sheet, height_of_sheet);
    this->setScene(scene);

    this->drawLine();

    //viewNote = nullptr;
}


VNotePaper::~VNotePaper()
{
    //delete viewNote;
    //delete lines;
    delete scene;
}

void VNotePaper::drawLine()
{
/*
    for (int i = 100; i < height_of_sheet - 100; i+=100)
    {
        lines[i/100 - 1] = new Lines(this, 100, i);
        scene->addItem(lines[i/100 - 1]);
    }

*/
}

QPoint VNotePaper::getMouseCord(int pos_x, int pos_y)
{
/*
    int local_x = 0, local_y = 0;
    for (int i = 0; i < 10; i++)
        for (int x = 10 + lines[i]->getx(); x <= width_of_lines + lines[i]->getx(); x+=10)
            for (int y = 3 + lines[i]->gety(); y < height_of_lines + lines[i]->gety(); y+=AbsLineY)
                if  ((pos_x >= x - 10) && (pos_x <= x) && (pos_y >= y - AbsLineY) && (pos_y <= y))
                {
                    local_x = x - 5;
                    local_y = y - AbsLineY/2;
                    ind = i;
                    return QPoint(local_x, local_y);
                }
    return QPoint(-1, -1);
*/
}


void VNotePaper::mouseMoveEvent(QMouseEvent *event)
{
    QPoint temp = getMouseCord(event->x(), event->y());
/*
    if (temp.x() == -1 && temp.y() == -1)
        return;


    if (viewNote == nullptr)
    {
        switch (length_next_note) {
        case 1:
            viewNote = new Note(this, nullptr, 0, temp.x(), temp.y());
            break;
        case 2:
            viewNote = new partNote(this, nullptr, 0, temp.x(), temp.y() );
            break;
        case 4:
            viewNote = new quaterNote(this, nullptr, 0, temp.x(), temp.y());
            break;
        case 8:
            viewNote = new eightNote(this, nullptr, 0, temp.x(), temp.y());
            break;
        case 16:
            viewNote = new sexteenthNote(this, nullptr, 0, temp.x(), temp.y());
            break;
        default:
            break;
        }
        scene->addItem(viewNote);
    }
    else
    {
        if (viewNote->getlen() != length_next_note)
        {
            delete viewNote;
            switch (length_next_note) {
            case 1:
                viewNote = new Note(this, nullptr, 0, temp.x(), temp.y());
                break;
            case 2:
                viewNote = new partNote(this, nullptr, 0, temp.x(), temp.y() );
                break;
            case 4:
                viewNote = new quaterNote(this, nullptr, 0, temp.x(), temp.y());
                break;
            case 8:
                viewNote = new eightNote(this, nullptr, 0, temp.x(), temp.y());
                break;
            case 16:
                viewNote = new sexteenthNote(this, nullptr, 0, temp.x(), temp.y());
                break;
            default:
                break;
            }
            scene->addItem(viewNote);
        }
        else
            viewNote->setPos(temp.x(), temp.y());
    }
*/
}


void VNotePaper::mousePressEvent(QMouseEvent *event)
{
/*
    QPoint temp = getMouseCord(event->x(), event->y());

    if (temp.x() == -1 && temp.y() == -1)
        return;

    connect(this, &MuseSheet::on_press_for_add_note, lines[ind], &Lines::get_signal_add_note);

    emit on_press_for_add_note(&temp, length_next_note);

    disconnect(this, &MuseSheet::on_press_for_add_note, lines[ind], &Lines::get_signal_add_note);
*/
}

void VNotePaper::get_len_next_note(int length)
{
    length_next_note = length;
}

VNotePaperScene::VNotePaperScene(QObject *parent, int w, int h)
    : QGraphicsScene{parent}
{
    this->setSceneRect(0, 0, w, h);
    this->test = new FTakt(this);
    this->test->show();
}

VNotePaperScene::~VNotePaperScene()
{

}
