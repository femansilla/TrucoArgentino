#include "clsJuego.h"

clsJuego::~clsJuego()
{
    //dtor
}

int clsJuego::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;

    error.set(mensaje.init(screen, event));
    if (error.get()) return error.get();

    error.set(baraja.init(screen, event/*, escala[14][4]*/));
    if (error.get()) return error.get();

    error.set(puntuacion_com.init(screen, event/*, escala[14][4]*/));
    if (error.get()) return error.get();

    error.set(puntuacion_player.init(screen, event/*, escala[14][4]*/));
    if (error.get()) return error.get();
}

int clsJuego::run()
{
    bool vuelta = true;
    int vuelta_mano = 0;

    while(vuelta)
    {
        error.set(baraja.darCartas());
        if (error.get()) return error.get();

        error.set(baraja.run(0));
        if (error.get()) return error.get();

        baraja.mano(vuelta_mano % 2);

        puntuacion_player.setPuntaje(puntuacion_player.getPuntaje());
        error.set(puntuacion_player.setPath());
        if (error.get()) return error.get();
        puntuacion_player.mostrar(150,50);

        puntuacion_com.setPuntaje(puntuacion_com.getPuntaje());
        error.set(puntuacion_com.setPath());
        if (error.get()) return error.get();
        puntuacion_com.mostrar(20,50);

        if(baraja.getGuardarpartida().pressed())
        {
            guardar_partida.setPuntos_player(puntuacion_player.getPuntaje());
            guardar_partida.setPuntos_COM(puntuacion_com.getPuntaje());
            guardar_partida.grabarEnDisco();

            mensaje.setMessage(12);
            mensaje.setPath();
            mensaje.mostrar(640, 240);
        }

        screen->refresh();
        //refresh_screen();

        if( puntuacion_com.getPuntaje() >= 30 ||
            puntuacion_player.getPuntaje() >= 30 )
            vuelta = false;

        vuelta_mano ++;
    }
}

//int clsJuego::refresh_screen()
//{
//    screen->clean(BLACK);
//
//    error.set(baraja.run(1));
//    if (error.get()) return error.get();
//
//    baraja.tira_com();
//
//    screen->refresh();
//}

void clsJuego::armar_escala()
{
    int n = 0;
    int number = 2;

    while(n < 16)
    {
        if(number == 12)
            number = 0;

        number ++;
        n++;

        if( n == 1 ||
            number == 8 ||
            number == 9 )
          continue;

        if( n < 14)
        {
            for (int i = 0; i < 4; i++)
            {
                if ( number == 4 ||
                     number == 5 ||
                     number == 6 )
                {
                    escala[n-2][i].setPalo(i+1);
                    escala[n-2][i].setNumero(number);
                }

                if (number == 7)
                {
                    if ( (i +1) == 1 ||
                         (i + 1) == 3)
                        continue;

                    escala[n-2][i].setPalo(i+1);
                    escala[n-2][i].setNumero(number);
                }

                if( number == 10 ||
                    number == 11 ||
                    number == 12)
                {
                    escala[n-4][i].setPalo(i+1);
                    escala[n-4][i].setNumero(number);
                }

                if (number == 1)
                {
                    if ( (i + 1) == 1 ||
                         (i + 1) == 2)
                        continue;

                    escala[n-4][i].setPalo(i+1);
                    escala[n-4][i].setNumero(number);
                }

                if ( number == 2 ||
                     number == 3 )
                {
                    escala[n-4][i].setPalo(i+1);
                    escala[n-4][i].setNumero(number);
                }

            }
        }


        if(n == 13)
        {
            escala[10][0].setPalo(3);
            escala[10][0].setNumero(7);
        }

        if(n == 14)
        {
            escala[11][0].setPalo(1);
            escala[11][0].setNumero(7);
        }

        if(n == 15)
        {
            escala[12][0].setPalo(2);
            escala[12][0].setNumero(1);
        }

        if(n == 16)
        {
            escala[13][0].setPalo(1);
            escala[13][0].setNumero(1);
        }
    }

    cout<<"escala armada"<<endl;

}

