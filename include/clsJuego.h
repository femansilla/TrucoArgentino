#ifndef CLSJUEGO_H
#define CLSJUEGO_H
#include <clsBaraja.h>
#include <clsError.h>
#include <clsEvent.h>
#include <clsScreen.h>
#include <clsButton.h>
#include <clsMaso.h>
#include <clsMensajes.h>
#include <clsGuardarPartida.h>

class clsJuego
{
    public:
        ~clsJuego();
        int init(clsScreen*, clsEvent*);
        int run();

        void armar_escala();

//        int refresh_screen();
//
//        bool guardarEnDisco(clsPuntos *);
//        bool leerDeDisco();
//
        clsGuardarPartida getPartida(){return guardar_partida;}

    private:
        clsError error;
        clsEvent *event;
        clsScreen *screen;

//        int puntaje_com;
//        int puntaje_player;

        clsMensajes mensaje;

        clsPuntos puntuacion_player;
        clsPuntos puntuacion_com;

        clsBaraja baraja;
        clsGuardarPartida guardar_partida;

        clsCarta escala[14][4];

};

#endif // CLSJUEGO_H
