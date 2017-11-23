#include "pika.h"

int pika::init(clsScreen *scr)
{
    this->screen = scr;
    setItems(7);
    char path[] = "IMAGENES/pika/0.gif";

    for(int i = 0; i < 7; i++)
    {
        setI(i);
        path[14] = i + 48;
        error.set(load(path));
        if(error.get())
        {
            return error.get();
        }
    }

    setI(0);
    return error.get();
}

void pika::animar()
{
    if(getI() >= 6)
    {
        setI(0);
    }
    else
    {
        setI(getI() + 1 );
    }

    paste(screen->getPtr());
}
