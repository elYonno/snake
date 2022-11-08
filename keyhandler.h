#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <QObject>
#include <QKeyEvent>

#include "engine.h"

class KeyHandler : public QObject
{
    Q_OBJECT
public:
    KeyHandler(Engine * engine);

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Engine * engine;
};

#endif // KEYHANDLER_H
