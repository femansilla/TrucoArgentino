#ifndef CLSBUTTON_H
#define CLSBUTTON_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsCarta.h>
#include <clsSprite.h>


class clsButton : public clsSprite
{
    protected:
        void inherit(){};

    private:
        clsEvent *event;
        clsScreen *screen;
        clsError error;

        bool used = false;

        int button;
        char path[100]= {0};

    public:

        int init(clsScreen *, clsEvent *);

        bool disabled();
        bool get_used(){return used;}
        void setUsed(bool);

        int getButton(){return button;};
        void setButton(int);

        char *getPath(){return path;};
        int setPath();

        void mostrar(int, int);

        bool pressed();
};

#endif // CLSBUTTON_H
