#include "clsCartas.h"


int clsCartas::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    error.set(0);
    setItems(1);

    setI(0);
    error.set(load("IMAGENES/maso02.png")); // maso azul para el vacio
    if(error.get()) return error.get();

//    setI(1);
//    error.set(load("IMAGENES/espada01.jpg"));
//    if(error.get()) return error.get();
//
//    setI(2);
//    error.set(load("IMAGENES/espada02.jpg"));
//    if(error.get()) return error.get();
//
//
//    setI(3);
//    error.set(load("IMAGENES/espada03.jpg"));
//    if(error.get()) return error.get();

    setX(0);
    setY(0);
    return error.get();
}

void clsCartas::jugada(int num_carta)
{
    setI(1);
    switch(num_carta)
    {

        case 1:         // CARTAS PJ
        {
            setX(360);
            setY(520);
        }break;

        case 2:
        {
            setX(600);
            setY(520);
        }break;

        case 3:
        {
            setX(480);
            setY(520);
        }break;

        case 4:         // CARTAS COM
        {
            setX(360);
            setY(50);
        }break;

        case 5:
        {
            setX(600);
            setY(50);
        }break;

        case 6:
        {
            setX(480);
            setY(50);
        }break;

    }
    paste(screen->getPtr());
}
