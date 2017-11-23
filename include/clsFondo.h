#ifndef CLSFONDO_H
#define CLSFONDO_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsError.h>
#include <adnConsts.h>
#include <clsSprite.h>


class clsFondo : public clsSprite
{
protected:
    void inherit(){};
private:
        clsEvent *event;
        clsScreen *screen;
        clsError error;
public:
    int init(clsScreen *, clsEvent *);

    void presentacion();
    void panio();
    void despedida();
    void ayuda();
};

#endif // CLSFONDO_H
