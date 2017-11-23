#ifndef CLSJUGADOR_H
#define CLSJUGADOR_H

#include <clsCarta.h>

class clsJugador
{
    public:
        clsJugador();
        ~clsJugador();

    protected:

    private:
        bool esMano();
        clsCarta cartas[3];
        //clsTurno turno[3];
};

#endif // CLSJUGADOR_H
