#include "clsRonda.h"

//clsRonda::clsRonda(clsCarta carta_com, clsCarta carta_player)
//{
//    this->carta_com = carta_com;
//    this->carta_player = carta_player;
//    rondas_com = 0;
//    rondas_pj = 0;
//}

clsRonda::~clsRonda()
{
    cout<<"Se elimino la ronda"<<endl;
}

void set_escala(clsCarta escala_parametro[][4])
{
//    escala = escala_parametro;
}

int clsRonda::comparar_cartas()
{
    if(get_altura(carta_player) > get_altura(carta_com))
        return 1;
    else
    {
        if(get_altura(carta_player) < get_altura(carta_com))
            return -1;
        else
            return 0;
    }
}


int clsRonda::get_altura(clsCarta carta)
{
    for(int f=0; f<14; f++)
    {
        for(int c=0; c<4; c++)
        {
//            escala[f][c].init(&screen, &event);

            if(match_carta(escala[f][c], carta ))
                return f;
        }
    }
}

bool clsRonda::match_carta(clsCarta carta_escala, clsCarta carta_juego)
{
    if(carta_escala.getNumero() == carta_juego.getNumero() &&
       strcmp(carta_escala.getPalo(), carta_juego.getPalo()))
    {
        cout<< "carta match"<<endl;
        return true;
    }

    else
        return false;
}
