#include "clsButton.h"

int clsButton::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    setItems(1);
    cout << "boton iniciado correctamente."<< endl;
    if(error.get()) return error.get();
}

void clsButton::mostrar(int x, int y)
{
    setI(button);

    setX(x - getWidth()/2);
    setY(y - getHeight()/2);

    paste(screen->getPtr());
}

bool clsButton::disabled()
{
    error.set(0);
    char boton[100]= {0};

    switch (button)
    {
    case 1:
        strcpy(boton,"envidodisabled");
        break;
    case 2:
        strcpy(boton,"realEnvidodisabled");
        break;
    case 3:
        strcpy(boton,"faltaEnvidodisabled");
        break;
    case 4:
        strcpy(boton,"trucodisabled");
        break;
    case 5:
        strcpy(boton,"reTrucodisabled");
        break;
    case 6:
        strcpy(boton,"valeCuatrodisabled");
        break;
    }

    strcpy(path, "IMAGENES/buttons/btn");
    strncat(path, boton,strlen(boton));
    strcat(path, ".png");

    error.set(load(path));
    if(error.get()) return error.get();
}

void clsButton::setButton(int btnSelected)
{
    button = btnSelected;
}

void clsButton::setUsed(bool value)
{
    used = value;
}

int clsButton::setPath()
{
    error.set(0);
    char boton[100]= {0};
    used = true;

    switch (button)
    {
    case 1:
        strcpy(boton,"envido");
        break;
    case 2:
        strcpy(boton,"realEnvido");
        break;
    case 3:
        strcpy(boton,"faltaEnvido");
        break;
    case 4:
        strcpy(boton,"truco");
        break;
    case 5:
        strcpy(boton,"reTruco");
        break;
    case 6:
        strcpy(boton,"valeCuatro");
        break;
    case 7:
        strcpy(boton,"alMazo");
        break;
    case 8:
        strcpy(boton,"salir");
        break;
    case 9:
        strcpy(boton,"ayuda");
        break;
    case 10:
        strcpy(boton,"jugar");
        break;
    case 11:
        strcpy(boton,"jugarFacil");
        break;
    case 12:
        strcpy(boton,"jugarMedio");
        break;
    case 13:
        strcpy(boton,"jugarDificil");
        break;
    case 14:
        strcpy(boton,"continuar");
        break;
    case 15:
        strcpy(boton,"help");
        break;
    case 16:
        strcpy(boton,"backToMenu");
        break;
    case 17:
        strcpy(boton,"guardarPartida");
        break;
    case 18:
        strcpy(boton,"Quiero");
        break;
    case 19:
        strcpy(boton,"NoQuiero");
        break;

    }

    strcpy(path, "IMAGENES/buttons/btn");
    strncat(path, boton,strlen(boton));
    strcat(path, ".PNG");

    setUsed(false);

    error.set(load(path));
    if(error.get()) return error.get();
}

bool clsButton::pressed()
{
    return was_click(event->getCursorX(), event->getCursorY());
}

