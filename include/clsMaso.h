#ifndef CLSMASO_H
#define CLSMASO_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsError.h>
#include <adnConsts.h>
#include <clsSprite.h>


class clsMaso : public clsSprite
{
    private:
        clsEvent *event;
        clsScreen *screen;
        clsError error;

    protected:
        void inherit() {};

    public:
        int init(clsScreen *, clsEvent *);
        int run();
        void pj();
        void com();
        void mostrar_mazo(int);
};

#endif // CLSMASO_H
