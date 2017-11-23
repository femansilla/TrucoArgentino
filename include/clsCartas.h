#ifndef CLSCARTAS_H
#define CLSCARTAS_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsSprite.h>


class clsCartas : public clsSprite
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
        void jugada(int );
//        void com();
};

#endif // CLSCARTAS_H
