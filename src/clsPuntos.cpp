#include "clsPuntos.h"

clsPuntos::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    setItems(1);
    cout << "puntaje iniciado correctamente."<< endl;
    if(error.get()) return error.get();
}

void clsPuntos::mostrar(int x, int y)
{
    setI(puntaje);

    setX(x /*- getWidth()/2*/);
    setY(y /*- getHeight()/2*/);

    paste(screen->getPtr());
}

void clsPuntos::setPuntaje(int puntajeSelected)
{
    puntaje = puntajeSelected;
}

int clsPuntos::setPath()
{
    error.set(0);
    char puntos[50]= {0};

    switch (puntaje)
    {
    case 1:
        strcpy(puntos,"puntaje01");
        break;
    case 2:
        strcpy(puntos,"puntaje02");
        break;
    case 3:
        strcpy(puntos,"puntaje03");
        break;
    case 4:
        strcpy(puntos,"puntaje04");
        break;
    case 5:
        strcpy(puntos,"puntaje05");
        break;
    case 6:
        strcpy(puntos,"puntaje06");
        break;
    case 7:
        strcpy(puntos,"puntaje07");
        break;
    case 8:
        strcpy(puntos,"puntaje08");
        break;
    case 9:
        strcpy(puntos,"puntaje09");
        break;
    case 10:
        strcpy(puntos,"puntaje10");
        break;
    case 11:
        strcpy(puntos,"puntaje11");
        break;
    case 12:
        strcpy(puntos,"puntaje12");
        break;
    case 13:
        strcpy(puntos,"puntaje13");
        break;
    case 14:
        strcpy(puntos,"puntaje14");
        break;
    case 15:
        strcpy(puntos,"puntaje15");
        break;
    case 16:
        strcpy(puntos,"puntaje16");
        break;
    case 17:
        strcpy(puntos,"puntaje17");
        break;
    case 18:
        strcpy(puntos,"puntaje18");
        break;
    case 19:
        strcpy(puntos,"puntaje19");
        break;
    case 20:
        strcpy(puntos,"puntaje20");
        break;
    case 21:
        strcpy(puntos,"puntaje21");
        break;
    case 22:
        strcpy(puntos,"puntaje22");
        break;
    case 23:
        strcpy(puntos,"puntaje23");
        break;
    case 24:
        strcpy(puntos,"puntaje24");
        break;
    case 25:
        strcpy(puntos,"puntaje25");
        break;
    case 26:
        strcpy(puntos,"puntaje26");
        break;
    case 27:
        strcpy(puntos,"puntaje27");
        break;
    case 28:
        strcpy(puntos,"puntaje28");
        break;
    case 29:
        strcpy(puntos,"puntaje29");
        break;
    case 30:
        strcpy(puntos,"puntaje30");
        break;
    default:
        strcpy(puntos,"puntaje0");
        break;
    }

    strcpy(path, "IMAGENES/puntos/");
    strncat(path, puntos,strlen(puntos));
    strcat(path, ".png");

    error.set(load(path));
    if(error.get()) return error.get();
}

