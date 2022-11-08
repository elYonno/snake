#ifndef ENGINE_H
#define ENGINE_H

#include <QTimer>

#include "snake.h"
#include "square.h"

class Engine : public QObject
{

    Q_OBJECT
public:
    Engine(Snake * snake);
    ~Engine();
    void setDirection(int direction);

signals:
    void crash(int score);

public slots:
    void update();

private:
    void checkEat();
    bool checkCollision();
    bool checkOutOfBounds();
    void gameOver();

    int newDirection = 2;
    int oldDirection = 2;
    int score = 0;

    Snake * snake;
    QTimer * loop;
    std::vector<Square *> snakeTiles;
    Square * food;
};

#endif // ENGINE_H
