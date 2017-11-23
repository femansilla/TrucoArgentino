#ifndef CLSGUARDARPARTIDA_H
#define CLSGUARDARPARTIDA_H
#include <iostream>
#include <stdio.h>
#include <clsMensajes.h>

class clsGuardarPartida
{
    public:
        void setPuntos_COM(int puntoCOM){ puntos_COM = puntoCOM;}
        void setPuntos_player(int puntoPlayer){ puntos_player = puntoPlayer;}

        int getPuntos_COM(){return puntos_COM;}
        int getPuntos_player(){return puntos_player;}

        bool leerDeDisco();
        bool grabarEnDisco();

    protected:

    private:
        int puntos_COM;
        int puntos_player;
        clsMensajes mensaje;
};

#endif // CLSGUARDARPARTIDA_H
