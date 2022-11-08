#include "square.h"

Square::Square() : x{50}, y{50}
{

}

Square::Square(int x, int y) : x{x}, y{y}
{

}

int Square::getX() const
{
    return x;
}

int Square::getY() const
{
    return y;
}

void Square::update(int direction)
{
    switch (direction)
    {
        case 1: // up
            y -= 10;
        break;
        case 2: // right
            x += 10;
        break;
        case 3: // down
            y += 10;
        break;
        case 4:
            x -= 10;
        break;
    }
}

void Square::update(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool Square::operator==(const Square &other) const
{
    return x == other.getX() && y == other.getY();
}
