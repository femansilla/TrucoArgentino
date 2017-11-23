#ifndef CLSPUNTOS_H
#define CLSPUNTOS_H
#include <clsEvent.h>
#include <clsError.h>
#include <clsScreen.h>
#include <clsSprite.h>


class clsPuntos : public clsSprite
{
    protected:
        void inherit(){};

    private:
        clsEvent *event;
        clsScreen *screen;
        clsError error;

        int puntaje;
        char path[100]= {0};

    public:
        int init(clsScreen *, clsEvent *);

        int getPuntaje(){return puntaje;};
        void setPuntaje(int);

        char *getPath(){return path;};
        int setPath();

        void mostrar(int, int);
};

#endif // CLSPUNTOS_H
