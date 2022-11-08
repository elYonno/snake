#include <string>
#include <iostream>

#include "snake.h"
#include "./ui_snake.h"

Snake::Snake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snake)
{
    ui->setupUi(this);
    this->setFixedSize(500, 400);

    scene = new QGraphicsScene(this);
    ui->playArea->setScene(scene);
    ui->playArea->setFixedSize(450, 350);
}

Snake::~Snake()
{
    delete ui;
}

void Snake::drawTiles(std::vector<Square *> squares, Square * food, int score)
{
    scene->clear();
    scene->addRect(0, 0, 400, 300);

    std::string title = "Snake - Score = " + std::to_string(score);
    this->setWindowTitle(QString::fromStdString(title));

    for (auto square : squares)
    {
        auto tile = scene->addRect(square->getX(), square->getY(), 10, 10);
        tile->setZValue(1.1);
        tile->setBrush(Qt::red);
    }

    auto tile = scene->addRect(food->getX(), food->getY(), 10, 10);
    tile->setZValue(1.1);
    tile->setBrush(Qt::yellow);
}

void Snake::gameOver(int score)
{
    std::string title = "Game Over - Score = " + std::to_string(score);
    this->setWindowTitle(QString::fromStdString(title));
}
