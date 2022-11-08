#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include "square.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Snake; }
QT_END_NAMESPACE

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();
    void drawTiles(std::vector<Square *> squares, Square * food, int score);

public slots:
    void gameOver(int score);

private:
    Ui::Snake *ui;
    QGraphicsScene * scene;
};
#endif // SNAKE_H
