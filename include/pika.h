#ifndef PIKA_H
#define PIKA_H

#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
#include <clsSprite.h>


class pika : public clsSprite
{
    public:
        int init(clsScreen*);
        void animar();

    protected:
        clsScreen *screen;
        clsError error;
        void inherit(){};

//    private:
};

#endif // PIKA_H
