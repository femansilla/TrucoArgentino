#include "clsFondo.h"

int clsFondo::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    setItems(4);

    setI(0);
    error.set(load("IMAGENES/presentacion.jpg"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("IMAGENES/panio.png"));
    if(error.get()) return error.get();

    setI(2);
    error.set(load("IMAGENES/despedida.jpg"));
    if(error.get()) return error.get();

    setI(3);
    error.set(load("IMAGENES/ayuda.png"));
    if(error.get()) return error.get();

    setX(0);
    setY(0);

    cout << "fondo iniciado correctamente\n";
    return error.get();
}

void clsFondo::presentacion()
{
    setI(0);
    setX(150);
    setY(0);
    paste(screen->getPtr());
}

void clsFondo::panio()
{
    setI(1);
    paste(screen->getPtr());
}

void clsFondo::despedida()
{
    setI(2);
    paste(screen->getPtr());
}
void clsFondo::ayuda()
{
    setI(3);
    paste(screen->getPtr());
}

