#ifndef CLSCARTA_H
#define CLSCARTA_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <cstring>
#include <clsSprite.h>


class clsCarta : public clsSprite
{
     protected:
        void inherit(){};
    private:
        clsEvent *event;
        clsScreen *screen;
        clsError error;
        int numero;
        char palo[10] = {0};
        char path[100]= {0};

    public:
        int init(clsScreen *, clsEvent *);

        char *getPalo(){ return palo;}
        void setPalo(int);

        int getNumero(){return numero;};
        void setNumero(int);

        char *getPath(){return path;};
        int setPath();

        void mostrar_init(int, int);
        void mover_carta(int);
        void mover_carta_com(int);
        void mostrar_jugada(int, int);
        void mostrar_init_player(int);
        void mostrar_init_com(int);


        //TODO: hacer constructor para inicializar el num en null y el palo en null.


};

#endif // CLSCARTA_H
