#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square();
    Square(int x, int y);

    int getX() const;
    int getY() const;

    void update(int direction);
    void update(int x, int y);

    bool operator==(const Square & other) const;

private:
    int x;
    int y;
};

#endif // SQUARE_H
