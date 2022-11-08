#include <random>

#include "engine.h"

Engine::Engine(Snake * snake) : snake{snake}
{
    loop = new QTimer();
    loop->setInterval(100);
    connect(loop, SIGNAL(timeout()), this, SLOT(update()));
    loop->start();

    snakeTiles.push_back(new Square());
    snakeTiles.push_back(new Square());
    snakeTiles.push_back(new Square());
    snakeTiles.push_back(new Square());

    food = new Square(150, 150);

    connect(this, SIGNAL(crash(int)), snake, SLOT(gameOver(int)));
}

Engine::~Engine()
{
    delete loop;
    delete food;
    snakeTiles.clear();
}

void Engine::setDirection(int newDirection)
{
    if ((this->oldDirection == 1 && newDirection == 3) ||
            (this->oldDirection == 2 && newDirection == 4) ||
            (this->oldDirection == 3 && newDirection == 1) ||
            (this->oldDirection == 4 && newDirection == 2))
        return;
    this->newDirection = newDirection;
}

void Engine::update()
{
    oldDirection = newDirection;

    auto head = snakeTiles.front();
    int x = head->getX(), y = head->getY();
    head->update(oldDirection);

    if (checkCollision()) return;
    if (checkOutOfBounds()) return;
    checkEat();

    for (int i = 1; i < snakeTiles.size(); i++)
    {
        auto body = snakeTiles[i];
        int temp_x = body->getX(), temp_y = body->getY();
        body->update(x, y);
        x = temp_x;
        y = temp_y;
    }

    snake->drawTiles(snakeTiles, food, score);
}

void Engine::checkEat()
{
    auto head = snakeTiles.front();
    if (*food == *head)
    {
        score++;
        auto tail = snakeTiles.back();
        snakeTiles.push_back(new Square(tail->getX(), tail->getY()));

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrX(0, 399);
        std::uniform_int_distribution<> distrY(0, 299);

        int x = (distrX(gen) / 10) * 10;
        int y = (distrY(gen) / 10) * 10;

        food->update(x, y);
    }
}

bool Engine::checkCollision()
{
    auto head = snakeTiles.front();
    for (int i = 1; i < snakeTiles.size(); i++)
    {
        if (*head == *snakeTiles[i])
        {
            gameOver();
            return true;
        }
    }
    return false;
}

bool Engine::checkOutOfBounds()
{
    auto head = snakeTiles.front();
    if (head->getX() >= 400 ||
            head->getX() < 0 ||
            head->getY() >= 300 ||
            head->getY() < 0)
    {
        gameOver();
        return true;
    } else
        return false;
}

void Engine::gameOver()
{
    emit crash(score);
    loop->stop();
}
