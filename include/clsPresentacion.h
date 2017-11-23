#ifndef CLSPRESENTACION_H
#define CLSPRESENTACION_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
#include <clsButton.h>
#include <clsJuego.h>
#include <clsTimer.h>

class clsPresentacion
{
protected:
    clsEvent *event;
    clsScreen *screen;
    clsError error;
    clsFondo fondo;
    clsTimer time;

    clsButton continuar;
    clsButton jugar;
    clsButton ayuda;
    clsButton boton_salir;

    clsJuego juego;

    public:
        int init(clsScreen *, clsEvent *);
        int run();
        int mouseCommand(Uint16);

};

#endif // CLSPRESENTACION_H
