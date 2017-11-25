#include "clsPresentacion.h"

int clsPresentacion::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;

    error.set(fondo.init(screen, event));
    if (error.get()) return error.get();

    error.set(continuar.init(screen, event));
    if (error.get()) return error.get();

    error.set(jugar.init(screen, event));
    if (error.get()) return error.get();

    error.set(ayuda.init(screen, event));
    if (error.get()) return error.get();

    error.set(boton_salir.init(screen, event));
    if (error.get()) return error.get();

    error.set(juego.init(screen, event));
    if (error.get()) return error.get();
}

int clsPresentacion::run()
{
    error.set(0);
    bool salir = false;
    FILE * partida = fopen("\partida.dat","rb");
    screen->clean(BLACK);              //Limpio la pantalla
    fondo.presentacion();

    continuar.setButton(14);
    error.set(continuar.setPath());
    if (error.get()) return error.get();
    continuar.mostrar(screen->getHeight()/2, 150);

    jugar.setButton(10);
    error.set(jugar.setPath());
    if (error.get()) return error.get();
    jugar.mostrar((screen->getHeight()/2), 270);

    ayuda.setButton(15);
    error.set(ayuda.setPath());
    if (error.get()) return error.get();
    ayuda.mostrar((screen->getHeight()/2), 390);

    boton_salir.setButton(8);
    error.set(boton_salir.setPath());
    if (error.get()) return error.get();
    boton_salir.mostrar((screen->getHeight()/2), 510);

    screen->refresh();

    while(!salir)  //Ciclo del programa
    {
        if(event->wasEvent())  //Verifico si hay evento
        {
            if(event->getEventType() == MOUSE_DOWN)  //Verifico si hay evento de teclado
            {
                mouseCommand(event->getKey());
            }
        }
    }
    return error.get();
}

int clsPresentacion::mouseCommand(Uint16 key)
{
    error.set(0);

    if(jugar.was_click(event->getCursorX(), event->getCursorY()))
        {
            error.set(juego.run());
            if (error.get()) return error.get();
            cout << "Aca se va a jugar\n";
        }

    if(continuar.was_click(event->getCursorX(), event->getCursorY()))
        {
            juego.getPartida().leerDeDisco();
            juego.run();
            cout << "Aca se va a cargar partida\n";
        }

    if(boton_salir.was_click(event->getCursorX(), event->getCursorY()))
        {
            fondo.despedida();
            screen->refresh();
            time.waitForKey(KEY_ESCAPE);
            exit(0);
        }

    if(ayuda.was_click(event->getCursorX(), event->getCursorY()))
        {
            fondo.setX(0);
            fondo.setY(0);
            fondo.ayuda();
            screen->refresh();
            time.waitForKey(KEY_ENTER);
        }

    run();
    return error.get();
}
