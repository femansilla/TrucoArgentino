#ifndef CLSMENSAJES_H
#define CLSMENSAJES_H
#include <clsEvent.h>
#include <clsError.h>
#include <clsScreen.h>
#include <clsSprite.h>


class clsMensajes : public clsSprite
{
    protected:
        void inherit(){};

    private:
        clsEvent *event;
        clsScreen *screen;
        clsError error;

        int message;
        char path[100]= {0};

    public:
        int init(clsScreen *, clsEvent *);

        int getMessage(){return message;};
        void setMessage(int);

        char *getPath(){return path;};
        int setPath();

        void mostrar(int, int);
};

#endif // CLSMENSAJES_H
