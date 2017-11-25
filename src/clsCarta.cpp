#include "clsCarta.h"

int clsCarta::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    screen = scr;
    event = ev;
    setItems(1);
    cout << "carta iniciada correctamente."<< endl;
    if(error.get()) return error.get();
}

void clsCarta::setPalo(int paloSelected)
{
    switch(paloSelected)
    {
    case 1:
        strcpy(this->palo,"espada");
        break;
    case 2:
        strcpy(this->palo,"basto");
        break;
    case 3:
        strcpy(this->palo,"oro");
        break;
    case 4:
        strcpy(this->palo,"copa");
        break;
    }
}

void clsCarta::setNumero(int numSelected)
{
    numero = numSelected;
}

int clsCarta::setPath()
{
    error.set(0);
    char carta[100]= {0};

    switch (numero)
    {
    case 1:
        strcpy(carta,palo);
        strncat(carta,"01", 2);
        break;
    case 2:
        strcpy(carta,palo);
        strncat(carta,"02", 2);
        break;
    case 3:
        strcpy(carta,palo);
        strncat(carta,"03", 2);
        break;
    case 4:
        strcpy(carta,palo);
        strncat(carta,"04", 2);
        break;
    case 5:
        strcpy(carta,palo);
        strncat(carta,"05", 2);
        break;
    case 6:
        strcpy(carta,palo);
        strncat(carta,"06", 2);
        break;
    case 7:
        strcpy(carta,palo);
        strncat(carta,"07", 2);
        break;
    case 8:
        strcpy(carta,palo);
        strncat(carta,"10", 2);
        break;
    case 9:
        strcpy(carta,palo);
        strncat(carta,"11", 2);
        break;
    case 10:
        strcpy(carta,palo);
        strncat(carta,"12", 2);
        break;
    case 15:
        strcpy(carta,"maso02");
        break;

    }

    if(carta[0] != 'm')
    {
        strcpy(path, "IMAGENES/Cartas/");
        strncat(path, carta,strlen(carta));
        strcat(path, ".png");
    }
    else
    {
        strcpy(path, "IMAGENES/Cartas/");
        strncat(path, carta,strlen(carta));
        strcat(path, ".png");
    }

    cout<<"el path es:"<<path<<endl;

    error.set(load(path));
    if(error.get()) return error.get();
}

void clsCarta::mostrar_init_player(int num_carta)
{
    setI(num_carta);

    switch(num_carta)
    {
        case 0:
        {
            setX(550);
            setY(520);
        }break;

        case 1:
        {
            setX(660);
            setY(520);

        }break;

        case 2:
        {
            setX(770);
            setY(520);
        }break;
    }
}

void clsCarta::mostrar_init_com(int num_carta)
{
    setI(num_carta);

    switch(num_carta)
    {
        case 0:
        {
            setX(550);
            setY(50);
        }break;

        case 1:
        {
            setX(660);
            setY(50);
        }break;

        case 2:
        {
            setX(770);
            setY(50);
        }break;
    }

}

void clsCarta::mostrar_init(int num_carta, int pj)
{
//    setI(num_carta);

    if(pj == 1)// CARTAS COM
        mostrar_init_com(num_carta);
    else // CARTAS PJ
        mostrar_init_player(num_carta);

    paste(screen->getPtr());
}


void clsCarta::mostrar_jugada(int num_carta, int pj)
{
    setI(num_carta);

    setX(getX());
    setY(getY());

    paste(screen->getPtr());
}

void clsCarta::mover_carta(int num_carta)
{
    switch(num_carta)
    {
    case 0:        // CARTAS PJ
    {
        setX(620);
        setY(250);
    }
    break;

    case 1:
    {
        setX(620-20);
        setY(250+20);
    }
    break;

    case 2:
    {
        setX(620-40);
        setY(250+40);
    }
    break;
    }


    paste(screen->getPtr());
}

void clsCarta::mover_carta_com(int num_carta)
{
    switch(num_carta)
    {
    case 0:        // CARTAS COM
    {
        setX(820);
        setY(250);
    }
    break;

    case 1:
    {
        setX(820+20);
        setY(250-20);
    }
    break;

    case 2:
    {
        setX(820+40);
        setY(250-40);
    }
    break;
    }

//    paste(screen->getPtr());
}
