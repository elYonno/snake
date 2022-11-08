#include "snake.h"
#include "engine.h"
#include "keyhandler.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Snake w;
    Engine * engine = new Engine(&w);
    KeyHandler * keyHandler = new KeyHandler(engine);

    a.installEventFilter(keyHandler);
    w.show();

    int result = a.exec();

    delete engine;
    delete keyHandler;

    return result;
}
