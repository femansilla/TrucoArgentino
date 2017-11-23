#include "clsMensajes.h"

clsMensajes::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    setItems(1);
    cout << "mensaje iniciado correctamente."<< endl;
    if(error.get()) return error.get();
}

void clsMensajes::mostrar(int x, int y)
{
    setI(message);

    setX(x /*- getWidth()/2*/);
    setY(y /*- getHeight()/2*/);

    paste(screen->getPtr());
}

void clsMensajes::setMessage(int mensajeSelected)
{
    message = mensajeSelected;
}

int clsMensajes::setPath()
{
    error.set(0);
    char mensaje[50]= {0};

    switch (message)
    {
    case 1:
        strcpy(mensaje,"quiero");
        break;
    case 2:
        strcpy(mensaje,"noQuiero");
        break;
    case 3:
        strcpy(mensaje, "envido");
        break;
    case 4:
        strcpy(mensaje,"envidoEnvido");
        break;
    case 5:
        strcpy(mensaje,"realEnvido");
        break;
    case 6:
        strcpy(mensaje,"faltaEnvido");
        break;
    case 7:
        strcpy(mensaje,"truco");
        break;
    case 8:
        strcpy(mensaje,"reTruco");
        break;
    case 9:
        strcpy(mensaje,"valeCuatro");
        break;
    case 10:
        strcpy(mensaje,"ganaste");
        break;
    case 11:
        strcpy(mensaje,"perdiste");
        break;
    case 12:
        strcpy(mensaje,"guardarPartidaOk");
        break;
    case 13:
        strcpy(mensaje,"guardarPartidaNoOk");
        break;
    }

    strcpy(path, "IMAGENES/mensajes/");
    strncat(path, mensaje,strlen(mensaje));
    strcat(path, ".png");

    error.set(load(path));
    if(error.get()) return error.get();
}
