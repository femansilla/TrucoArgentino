#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <clsError.h>
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsText.h>
#include <clsPresentacion.h>
#include <clsMaso.h>
//#include <clsCartas.h>
//#include <clsBaraja.h>
#include <clsButton.h>
//#include <clsRonda.h>
#include <clsJuego.h>

class clsMotor
{
    protected:
        clsEvent event;
        clsMode mode;
        clsScreen screen;
        clsError error;
        clsPresentacion presentacion;
//        clsText texto;

//        clsJuego juego;

    public:
        int init();
        int run();
        int refresh_screen();
};

#endif // CLSMOTOR_H
