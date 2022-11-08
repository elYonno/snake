#include "keyhandler.h"

KeyHandler::KeyHandler(Engine * engine) : engine(engine)
{

}

bool KeyHandler::eventFilter(QObject * object, QEvent * event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent * key = static_cast<QKeyEvent*> (event);
        bool set = false;

        if (key->key() == Qt::Key_W)
        {
            engine->setDirection(1);
            set = true;
        } if (key->key() == Qt::Key_D)
        {
            engine->setDirection(2);
            set = true;
        } if (key->key() == Qt::Key_S)
        {
            engine->setDirection(3);
            set = true;
        } if (key->key() == Qt::Key_A)
        {
            engine->setDirection(4);
            set = true;
        }

        if (set) return set;
        else return QObject::eventFilter(object, event);
    } else {
        return QObject::eventFilter(object, event);
    }
}
