#include "clsMaso.h"

int clsMaso::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    setItems(2);

    setI(0);
    error.set(load("IMAGENES/maso01.png"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("IMAGENES/maso02.png"));
    if(error.get()) return error.get();

    setX(0);
    setY(0);

    cout << "Maso iniciado correctamente\n";
    return error.get();
}

void clsMaso::pj()
{
    setI(1);
    setX(930);
    setY(520);
    paste(screen->getPtr());

}

void clsMaso::com()
{
    setI(1);
    setX(420);
    setY(50);
    paste(screen->getPtr());
}

void clsMaso::mostrar_mazo(int flag)
{
    if(flag)
        com();
    else
        pj();
    //screen->refresh();
}
