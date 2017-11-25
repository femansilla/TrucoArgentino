#include "clsBaraja.h"

clsBaraja::~clsBaraja()
{

}

int clsBaraja::init(clsScreen *scr, clsEvent *ev/*, clsCarta escal[14][4]*/)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    cout << "Baraja iniciada correctamente."<< endl;
    random.init();

    error.set(texto.init());
    if (error.get()) return error.get();
    error.set(texto.loadFont("FONTS/Griffy-Regular.ttf", 36));
    if (error.get()) return error.get();
    texto.setFontColor(WHITE);

    error.set(fondo.init(screen, event));
    if (error.get()) return error.get();

    error.set(mazo.init(screen, event));
    if (error.get()) return error.get();

    error.set(mensaje.init(screen, event));
    if (error.get()) return error.get();

    error.set(envido.init(screen, event));
    if (error.get()) return error.get();

    error.set(envido_envido.init(screen, event));
    if (error.get()) return error.get();
    envido_envido.setUsed(false);

    error.set(real_envido.init(screen, event));
    if (error.get()) return error.get();

    error.set(falta_envido.init(screen, event));
    if (error.get()) return error.get();

    error.set(quiereEnvido.init(screen, event));
    if (error.get()) return error.get();

    error.set(noQuiereEnvido.init(screen, event));
    if (error.get()) return error.get();

    error.set(truco.init(screen, event));
    if (error.get()) return error.get();

    error.set(re_truco.init(screen, event));
    if (error.get()) return error.get();

    error.set(vale_4.init(screen, event));
    if (error.get()) return error.get();

    error.set(quiereTruco.init(screen, event));
    if (error.get()) return error.get();

    error.set(noQuiereTruco.init(screen, event));
    if (error.get()) return error.get();

    error.set(abandonar.init(screen, event));
    if (error.get()) return error.get();

    error.set(guardarPartida.init(screen, event));
    if (error.get()) return error.get();

    error.set(puntuacion_com.init(screen, event));
    if (error.get()) return error.get();

    error.set(puntuacion_player.init(screen, event));
    if (error.get()) return error.get();

//    ronda.set_escala(escala);

//    this->escala = escala;

    if(error.get()) return error.get();
    return error.get();
}

void clsBaraja::mezclar()
{
    int contWhile=0, conFor=0, _palo=0, _numero=0, ok=0;
    int p = 0;
    int n = 0;
    bool seguir = false;

    while(contWhile < 12)
    {
        _palo = random.getNumber(4);
        _numero = random.getNumber(10);
        for(conFor=0; conFor < 12; conFor += 2)
        {
            if(*(ptrSel + conFor) == _numero)
            {
                if(*(ptrSel + conFor+1) == _palo)
                {
                    ok = 1;
                }
            }
        }

        if(ok == 0)
        {
            *(ptrSel + contWhile) = _numero;
            contWhile++;
            *(ptrSel + contWhile) = _palo;
            contWhile++;
        }
        else
        {
            ok=0;
        }
    }
}

int clsBaraja::darCartas()
{
    error.set(0);

    mezclar();

    int num = 0;

    for(int conFor=0; conFor < 12; conFor += 2)
    {
        if((conFor/2) < 3)
        {
            error.set(cartas_player[conFor/2].init(screen, event));
            if (error.get()) return error.get();

            cartas_player[conFor/2].setNumero(*(ptrSel + conFor) + 1);
//            cout << "numero de carta: "<<*(ptrSel + conFor) + 1 <<endl;

            cartas_player[conFor/2].setPalo(*(ptrSel + conFor+1) + 1);
//            cout << "palo de carta: "<<*(ptrSel + conFor+1) + 1<<endl;

            error.set(cartas_player[conFor/2].setPath());
//            cout <<"error: "<< error.get()<< endl;
            if(error.get()) return error.get();

            if(*(ptrSel + conFor) >= 8)
            {
                num = *(ptrSel + conFor) + 3;
                cartas_player[conFor/2].setNumero((num));
            }

        }
        else
        {
            error.set(cartas_com[(conFor/2)-3].init(screen, event));
            if (error.get()) return error.get();

            cartas_com[(conFor/2)-3].setNumero(*(ptrSel + conFor) + 1);
//            cout << "numero de carta: "<<*(ptrSel + conFor) + 1 <<endl;

            cartas_com[(conFor/2)-3].setPalo(*(ptrSel + conFor+1) + 1);
//            cout << "palo de carta: "<<*(ptrSel + conFor+1) + 1<<endl;

            error.set(cartas_com[(conFor/2)-3].setPath());
//            cout <<"error: "<< error.get()<< endl;
            if(error.get()) return error.get();

            if(*(ptrSel + conFor) >= 7)
            {
                num = *(ptrSel + conFor) + 3;
                cartas_player[conFor/2].setNumero((num));
            }
        }
    }

    return error.get();
}

int clsBaraja::run(int flag)
{
    error.set(0);
    screen->clean(BLACK);

    fondo.panio();

    texto.write("COM", 20, 10, screen->getPtr());
    texto.write("PLAYER", 130, 10, screen->getPtr());
//    puntuacion_com.mostrar(20,50);
//    puntuacion_player.mostrar(150,50);

    quiereEnvido.setButton(18);
    error.set(quiereEnvido.setPath());
    if (error.get()) return error.get();

    noQuiereEnvido.setButton(19);
    error.set(noQuiereEnvido.setPath());
    if (error.get()) return error.get();

    quiereTruco.setButton(18);
    error.set(quiereTruco.setPath());
    if (error.get()) return error.get();
    noQuiereTruco.setButton(19);
    error.set(noQuiereTruco.setPath());
    if (error.get()) return error.get();

    envido.setButton(1);
    error.set(envido.setPath());
    if (error.get()) return error.get();
    envido.mostrar(76, 590);

    real_envido.setButton(2);
    error.set(real_envido.setPath());
    if (error.get()) return error.get();
    real_envido.mostrar(227, 590);

    falta_envido.setButton(3);
    error.set(falta_envido.setPath());
    if (error.get()) return error.get();
    falta_envido.mostrar(378, 590);

    truco.setButton(4);
    error.set(truco.setPath());
    if (error.get()) return error.get();
    truco.mostrar(76, 666);

    re_truco.setButton(4);
    error.set(re_truco.setPath());
    if (error.get()) return error.get();
    //re_truco.mostrar(76, 666);

    vale_4.setButton(4);
    error.set(vale_4.setPath());
    if (error.get()) return error.get();
    //vale_4.mostrar(76, 666);

    abandonar.setButton(7);
    error.set(abandonar.setPath());
    if (error.get()) return error.get();
    abandonar.mostrar(227, 666);

    guardarPartida.setButton(17);
    error.set(guardarPartida.setPath());
    if (error.get()) return error.get();
    guardarPartida.mostrar(1100, 50);

    mostrar_cartas(flag);
    mazo.mostrar_mazo(flag);
    screen->refresh();

    return error.get();

}

void clsBaraja::mostrar_cartas_player(int flag)
{
    for (int i = 0; i<3; i++)
    {
        if(flag == 1)
            cartas_player[i].mostrar_jugada(i, 0);
        else
            cartas_player[i].mostrar_init(i, 0);
    }
}

void clsBaraja::mostrar_cartas_com(int flag)
{
    int numaux = 0;

    for (int i = 0; i<3; i++)
    {
        numaux = cartas_com[i].getNumero();

        if( flag && cartas_com[i].getMostrar() )
        {
            cartas_com[i].mover_carta_com(i);
            cartas_com[i].mostrar_jugada(i, 1);
        }
         else
        {
            cartas_com[i].setNumero(15);
            cartas_com[i].setPath();
            cartas_com[i].mostrar_init(i, 1);
            cartas_com[i].setNumero(numaux);
        }
    }
}

void clsBaraja::mostrar_cartas(int flag)
{
    mostrar_cartas_player(flag);
    mostrar_cartas_com(flag);
}

bool clsBaraja::carta_pressed(int x, int y)
{
    bool retorno = false;

    for (int i = 0; i<3; i++)
    {
        if(cartas_player[i].was_click(x, y))
        {
            retorno = true;
            carta_player_selected = cartas_player[i];
            cartas_player[i].mover_carta(i);
            break;
        }
    }
    return retorno;
}

int clsBaraja::getTanto(clsCarta mano[3])
{
    int palos[4]= {0,0,0,0};
    int num = 0;
    for (int i = 0; i<3; i++)
    {
        switch(mano[i].getPalo()[0])
        {
        case 'e':
            palos[0]++;
            break;

        case 'b':
            palos[1]++;
            break;

        case 'o':
            palos[2]++;
            break;

        case 'c':
            palos[3]++;
            break;
        }
    }

    int pos, cant = 0;

    for(int p = 0; p < 4; p++)
    {
        if (palos[p] > cant)
        {
            cant = palos[p];
            pos = p;
        }
    }

    int tanto = 0;
    int negras = 0;
    char palo[10] = {0};

    switch(cant)
    {
    case 1:     // un paisano de cada pueblo
    {
        for(int p = 0; p < 3; p++)
        {
            if ( mano[p].getNumero() > tanto &&
                    ( mano[p].getNumero() != 10 &&
                      mano[p].getNumero() != 11 &&
                      mano[p].getNumero() != 12 ) )
                tanto = mano[p].getNumero();
        }
    }
    break;

    default:
    {
        switch(pos)
        {
        case 0:
            strcpy(palo,"espada");
            break;

        case 1:
            strcpy(palo,"basto");
            break;

        case 2:
            strcpy(palo,"oro");
            break;

        case 3:
            strcpy(palo,"copa");
            break;
        }

        for(int i = 0; i<3; i++)
        {
            if (strcmp(mano[i].getPalo(), palo) == 0)
            {
                if ( mano[i].getNumero() != 10 &&
                        mano[i].getNumero() != 11 &&
                        mano[i].getNumero() != 12 )
                    tanto += mano[i].getNumero();
                else
                    negras++;

            }
        }

        if(negras == 2)
            tanto = 20;
        else
            tanto += 20;

    }
    break;
    }

    cout<<"tantos "<< tanto<<endl;
    return tanto;
}

int clsBaraja::contar_cartas( clsCarta carta_pj)
{
    int mayores, blancas = 0;

//usar comparar_cartas(clsCarta carta_pj) => contar mayores a carta_pj
//    ###si tiene mas de dos mayores, mata (mata con menor / mata con mayor)
//    ###si tiene una sola mayor => ver rango escala
//    ###si tiene todas menores => ver rango escala -> tirar menor

    for (int i = 0; i < 3 ; i++)
    {
        if(ronda.get_altura(cartas_com[i]) > ronda.get_altura(carta_pj))
            mayores ++;
    }

    if(mayores >= 2)
    {

    }

}

bool clsBaraja::parda(clsCarta carta_pj)
{
    int altura_1 = 0;
    int altura_2 = 0;
    int altura_3 = 0;
    int altura_pj = ronda.get_altura(carta_pj);

    altura_1 = ronda.get_altura(cartas_com[0]);
    altura_2 = ronda.get_altura(cartas_com[1]);
    altura_3 = ronda.get_altura(cartas_com[2]);

    if( altura_pj != altura_1 &&
        altura_pj != altura_2 &&
        altura_pj != altura_3 )
    return false;


    int index, mayor_3 = 0;
    clsCarta carta_mayor;

    for (int i = 0; i < 3; i++)
    {
        if(! (ronda.get_altura(cartas_com[i]) == ronda.get_altura(carta_pj) ))
    {
        if (ronda.get_altura(cartas_com[i]) > 8)
            {
                mayor_3 = 1;
                if(index == 0)
                    parda_index_mata = i;
                else
                {
                    if (ronda.get_altura(cartas_com[i]) > ronda.get_altura(cartas_com[index]))
                        parda_index_mata = i;
                }
            }
        }
        else
            parda_index_tira = i;
        }

    if (mayor_3 == 0)
        return false;
    else
        return true;

}

void clsBaraja::comparar_tantos()
{
    if (tantos_com > tantos_player)
    {
        cout<< tantos_com <<"son mejores. Tu no metes cabra :P"<<endl;
        mensaje.setMessage(11);
        mensaje.setPath();
        mensaje.mostrar(640, 250);
        puntos_COM += puntosEnvido;
    }
    else
    {
        if(tantos_com < tantos_player)
            {
                mensaje.setMessage(10);
                mensaje.setPath();
                mensaje.mostrar(640, 250);
                cout<<"Son buenas. Te espero a la salida"<<endl;
                puntos_player += puntosEnvido;
            }
        else
        {
            if(manita)
            {
                mensaje.setMessage(11);
                mensaje.setPath();
                mensaje.mostrar(640, 250);
                cout<< tantos_com<< " y soy mano. Bailame ie ieeee"<<endl;
                puntos_COM += puntosEnvido;
            }
            else
            {
                mensaje.setMessage(10);
                mensaje.setPath();
                mensaje.mostrar(640, 250);
                cout<< tantos_player<< " y soy manooo. Turn down for what...."<<endl;
                puntos_player += puntosEnvido;
            }
        }
    }

    screen->refresh();
    tiempo.wait(2*100);
}

void clsBaraja::re_envido(int case_env)
{
    mensaje.setMessage(case_envido+3);
    mensaje.setPath();
    mensaje.mostrar(640, 250);
    screen->refresh();
    tiempo.wait(2*100);
    calcularPuntosEnvido(case_envido);
}

int clsBaraja::com_decidir_envido()
{
    int  decision = 0;

    if(canto_envido)
    {
        tantos_com = 28; // desetear, es para prueba
        if( tantos_com <= 23 )
        {
            decision = random.getNumber(3);
            switch(decision)
            {
                case 1:
                {
                    envido_quiere = 0; // no quiere
                    mensaje.setMessage(2);
                    mensaje.setPath();
                    mensaje.mostrar(640, 250);
                    screen->refresh();
                    tiempo.wait(2*100);
                    puntos_player += cantos_envido;
                    return false;
                }break;

                default:
                {
                    envido_quiere = 1; // quiere
                    mensaje.setMessage(1);
                    mensaje.setPath();
                    mensaje.mostrar(640, 250);
                    screen->refresh();
                    tiempo.wait(2*100);
                    calcularPuntosEnvido(case_envido);
                    comparar_tantos();
                    return true;
                }break;
            }
        }

        else
        {
            if(falta_envido.get_used())
            {
                calcularPuntosEnvido(3);
                if ( tantos_com >= 28 &&
                     tantos_com <= 33 )
                {
                    envido_quiere = 1;
                    mensaje.setMessage(1);
                    mensaje.setPath();
                    mensaje.mostrar(640, 250);
                    screen->refresh();
                    tiempo.wait(2*100);
                    calcularPuntosEnvido(3);
                    comparar_tantos();
                    return true;
                }
                else
                {
                    mensaje.setMessage(2);
                    mensaje.setPath();
                    mensaje.mostrar(640, 250);
                    screen->refresh();
                    tiempo.wait(2*100);
//                    puntos_player++;
                    return false;
                }
            }

            if(real_envido.get_used())
            {
                calcularPuntosEnvido(2);
                if(tantos_com < 26)
                {
                    mensaje.setMessage(2);
                    mensaje.setPath();
                    mensaje.mostrar(640, 250);
                    screen->refresh();
                    tiempo.wait(2*100);
                    puntos_player += cantos_envido;
                    return false;
                }

                if ( tantos_com >= 26 &&
                     tantos_com <= 28 )
                {
                    envido_quiere = 1;
                    mensaje.setMessage(1);
                    mensaje.setPath();
                    mensaje.mostrar(640, 250);
                    screen->refresh();
                    tiempo.wait(4*100);
                    //calcularPuntosEnvido(2);
                    comparar_tantos();
                    return true;
                }


                if ( tantos_com > 28 &&
                     tantos_com <= 33 )
                {
                    case_envido = 3;
//                    mensaje.setMessage(case_envido+3);
//                    mensaje.setPath();
//                    mensaje.mostrar(640, 250);
//                    screen->refresh();
//                    tiempo.wait(2*100);
//                    calcularPuntosEnvido(3);
                    re_envido(case_envido);
                    return 2;
                }
            }

            if(envido.get_used())
            {
                calcularPuntosEnvido(0);
                if ( tantos_com >= 24 &&
                     tantos_com <= 28)
                {
                    case_envido = random.getNumber(4);
                    while ( case_envido == 3)
                        case_envido = random.getNumber(4);

                    if(case_envido == 0)
                    {
                        envido_quiere = 1;
                        mensaje.setMessage(1);
                        mensaje.setPath();
                        mensaje.mostrar(640, 250);
                        screen->refresh();
                        tiempo.wait(2*100);
                        calcularPuntosEnvido(case_envido);
                        comparar_tantos();
                        return true;
                    }
                    else
                    {
                        re_envido(case_envido);
                        return 2;
                    }


                }


                if ( tantos_com >= 28 &&
                     tantos_com <= 30 )
                {
                    case_envido = random.getNumber(4);
                    while (case_envido == 0 ||
                           case_envido == 3)
                        case_envido = random.getNumber(4);

//                    mensaje.setMessage(case_envido+3);
//                    mensaje.setPath();
//                    mensaje.mostrar(640, 250);
//                    screen->refresh();
//                    tiempo.wait(2*100);
//                    calcularPuntosEnvido(case_envido);
                    re_envido(case_envido);
                    return 2;
                }


                if ( tantos_com >= 30 &&
                     tantos_com <= 33 )
                {
                    case_envido = random.getNumber(4);
                    while (case_envido == 0 )
                        case_envido = random.getNumber(4);

//                    mensaje.setMessage(case_envido+3);
//                    mensaje.setPath();
//                    mensaje.mostrar(640, 250);
//                    screen->refresh();
//                    tiempo.wait(2*100);
//                    calcularPuntosEnvido(case_envido);
                    re_envido(case_envido);
                    return 2;
                }
            }


            if(envido_envido.get_used())
            {
                calcularPuntosEnvido(1);

                if ( tantos_com >= 26 &&
                     tantos_com <= 28 )
                {
                    envido_quiere = 1;
                    mensaje.setMessage(1);
                    mensaje.setPath();
                    mensaje.mostrar(640, 250);
                    screen->refresh();
                    tiempo.wait(2*100);
                    calcularPuntosEnvido(1);
                    comparar_tantos();
                    return true;
                }


                if ( tantos_com >= 28 &&
                     tantos_com <= 33 )
                {
                    case_envido = random.getNumber(4);
                    while ( case_envido == 0 ||
                            case_envido == 1)
                        case_envido = random.getNumber(4);

//                    mensaje.setMessage(case_envido+3);
//                    mensaje.setPath();
//                    mensaje.mostrar(640, 250);
//                    screen->refresh();
//                    tiempo.wait(2*100);
//                    calcularPuntosEnvido(case_envido);
                    re_envido(case_envido);
                    return 2;
                }
            }
        }
    }
}

bool clsBaraja::regla_envido()
{
//////////////////////////

   if(! canto_envido)
   {
        quiereEnvido.mostrar(320, 258);
        noQuiereEnvido.mostrar(320, 458);
        if ( tantos_com < 20)
        {
            case_envido = random.getNumber(4);

            while ( case_envido == 3 )
              case_envido = random.getNumber(4);

            if(case_envido == 1)
            {
                mensaje.setMessage(2);
                mensaje.setPath();
                mensaje.mostrar(640, 250);
                screen->refresh();
                puntos_player++;
                return false;
            }
            else
            {
                mensaje.setMessage(case_envido+3);
                mensaje.setPath();
                mensaje.mostrar(640, 250);
                screen->refresh();
                calcularPuntosEnvido(case_envido);
                return true;
            }
        }


        if ( tantos_com >= 20 &&
             tantos_com <= 29 )
        {
            case_envido = random.getNumber(4);

            while ( case_envido == 1 ||
                    case_envido == 3 )
              case_envido = random.getNumber(4);

            mensaje.setMessage(case_envido+3);
            mensaje.setPath();
            mensaje.mostrar(640, 250);
            screen->refresh();
            calcularPuntosEnvido(case_envido);
            return true;
        }


        if ( tantos_com == 30 )
        {
            case_envido = random.getNumber(4);

            while ( case_envido == 1 )
              case_envido = random.getNumber(4);

            mensaje.setMessage(case_envido+3);
            mensaje.setPath();
            mensaje.mostrar(640, 250);
            screen->refresh();
            calcularPuntosEnvido(case_envido);
            return true;
        }

        if ( tantos_com == 31 )
        {
            case_envido = random.getNumber(4);

            while ( case_envido == 0 ||
                    case_envido == 1 )
              case_envido = random.getNumber(4);

            mensaje.setMessage(case_envido+3);
            mensaje.setPath();
            mensaje.mostrar(640, 250);
            screen->refresh();
            calcularPuntosEnvido(case_envido);
            return true;
        }


        if ( tantos_com >= 32 &&
             tantos_com <= 33 )
        {
            case_envido = 3;
            mensaje.setMessage(case_envido+3);
            mensaje.setPath();
            mensaje.mostrar(640, 250);
            screen->refresh();
            calcularPuntosEnvido(case_envido);
            return true;
        }
   }
}

int clsBaraja::get_grupo_escala(clsCarta carta)
{
    if (ronda.get_altura(carta) > 9)
    {
        return 1;
    }

    if (ronda.get_altura(carta) > 6)
    {
        return 2;
    }

    if (ronda.get_altura(carta) > 3)
    {
        return 3;
    }

    return 4;
}

clsCarta clsBaraja::buscar_menor()
{
    if(ronda.get_altura(cartas_com[0]) >= ronda.get_altura(cartas_com[1]) &&
            ronda.get_altura(cartas_com[0]) >= ronda.get_altura(cartas_com[2]))
            {
                cartas_com[0].setMostrar(true);
                return cartas_com[0];
            }

    if(ronda.get_altura(cartas_com[1]) >= ronda.get_altura(cartas_com[0]) &&
            ronda.get_altura(cartas_com[1]) >= ronda.get_altura(cartas_com[2]))
            {
                cartas_com[1].setMostrar(true);
                return cartas_com[1];
            }

    if (ronda.get_altura(cartas_com[2]) >= ronda.get_altura(cartas_com[0]) &&
            ronda.get_altura(cartas_com[2]) >= ronda.get_altura(cartas_com[1]))
            {
                cartas_com[2].setMostrar(true);
                return cartas_com[2];
            }
}

void clsBaraja::buscar_carta_usada(char *carta_used)
{
    for(int i = 0; i < 3; i++)
    {
        if(strcmp(cartas_com[i].getPath(),carta_used) == 0)
            cartas_com[i].setUsed(true);
    }
}


clsCarta clsBaraja::tira_com()
{
    //int escala_divida[3][4];
    int grupo = 0;

    int grupo_1 = 0;
    int grupo_2 = 0;
    int grupo_3 = 0;
    int grupo_4 = 0;

    for (int i = 0; i < 3; i++)
    {
        grupo = get_grupo_escala(cartas_com[i]);

        switch (grupo)
        {
        case 1:
            //escala_divida[i][grupo - 1];
            grupo_1++;
        break;

        case 2:
            //escala_divida[i][grupo - 1];
            grupo_2++;
        break;

        case 3:
            //escala_divida[i][grupo - 1];
            grupo_3++;
        break;

        case 4:
            //escala_divida[i][grupo - 1];
            grupo_4++;
        break;

        }
    }
    int index = 0;
    clsCarta carta_tira;

    if(grupo_1 == 3 )
    {
        carta_tira = buscar_menor();
        return carta_tira;
    }

    if( grupo_2 == 3 ||
        grupo_3 == 3 ||
        grupo_4 == 3 )
        {
            index = random.getNumber(3);
            cartas_com[index].setMostrar(true);
            carta_tira = cartas_com[index];
            return carta_tira;
        }

    while( true )
    {
        index = random.getNumber(3);
        if(! (get_grupo_escala(cartas_com[index]) == 1))
        {
            if(!cartas_com[index].getUsed())
            {
                carta_tira = cartas_com[index];
                carta_tira.setMostrar(true);
                cartas_com[index].setMostrar(true);
                break;
            }
        }
    }
    return carta_tira;
}
void clsBaraja::jugada_com(int mano)
{
    if (mano == 0)
    {
        switch(i)
        {
            case 1:
                primera_ronda_com(mano);
            break;
            case 2:
                segunda_ronda_com();
            break;
            case 3:
                tercera_ronda_com();
            break;
            default:
                break;
        }

    }
    if (mano == 1)
    {
        switch(i)
        {
            case 1:
                primera_ronda_com(mano);
            break;
            case 2:
                segunda_ronda_com();
            break;
            case 3:
                tercera_ronda_com();
            break;
            default:
                break;
        }
//
//        if( i == 1)
//        {
//
//        }

    }
    else
    {
//        com_decidir_envido();
        if(regla_envido())
            {
                puntos_COM += puntosEnvido;
//                tiempo.wait(2*100);
//                mensaje.setMessage(11);
//                mensaje.setPath();
//                mensaje.mostrar(640, 250);
//                screen->refresh();
//                tiempo.wait(2*100);
            }
//        if(regla_envido() == 0)
//            {
//                tiempo.wait(2*100);
//                mensaje.setMessage(10);
//                mensaje.setPath();
//                mensaje.mostrar(640, 250);
//                screen->refresh();
//                tiempo.wait(2*100);
//            }

        //ver carta pj
//        carta_player_selected;

    }


//    int var_pensar = contar_cartas();
//    carta_com_selected = cartas_com[var_pensar];
//    cartas_com[var_pensar].setPath();
//    cartas_com[var_pensar].mover_carta_com(var_pensar);
}
void clsBaraja::primera_ronda_com(int manoParaEnvido)
{
    if(manoParaEnvido)
    {
        if(regla_envido())
        {
            puntos_COM += puntosEnvido;
//            tiempo.wait(2*100);
//
//            jugada_player(flag) //flag para habilitar los botones si se retruco envido o truco.
//            tiempo.wait(2*100);
        }
//        else
//        {
//            tiempo.wait(2*100);
//            mensaje.setMessage(10);
//            mensaje.setPath();
//            mensaje.mostrar(640, 250);
//            tiempo.wait(2*100);
//        }

        if(case_envido == 0)
        {
            tira_com();  //necesito que saber que carta mover de com, con un index.
        }
    }
    else
        {
            carta_com_selected = tira_com();
            //mostrar_cartas_com(1);
        }
}

void clsBaraja::segunda_ronda_com()
{
    envido.disabled();
    envido.mostrar(76, 590);
    real_envido.disabled();
    real_envido.mostrar(227, 590);
    falta_envido.disabled();
    falta_envido.mostrar(378, 590);

    buscar_carta_usada(carta_com_selected.getPath());

    jugar_truco();

    carta_com_selected = tira_com();
    //mostrar_cartas_com(1);



}
void clsBaraja::tercera_ronda_com()
{

}


int clsBaraja::mouseCommandEnvido()
{
        if(noQuiereEnvido.pressed())
        {
            puntos_COM += cantos_envido;
            return 0;
        }

        if(quiereEnvido.pressed())
        {
            comparar_tantos();
            return 1;
        }

        if(abandonar.pressed())
        {
            puntos_COM += cantos_envido; // + puntos truco  ;
            return 2;
        }
}
int clsBaraja::mouseCommandTruco()
{
        if(noQuiereTruco.pressed())
        {
            puntos_COM += cantos_truco;
            return 0;
        }

        if(quiereTruco.pressed())
        {
            //comparar_tantos();
            return 1;
        }

        if(abandonar.pressed())
        {

            //puntos_COM += cantos_envido; // + puntos truco  ;
            return 2;
        }
}

void clsBaraja::jugar_envido()
{
    if( ! envido.get_used() &&
        ! real_envido.get_used() &&
        ! falta_envido.get_used() )

    {
        if( envido.pressed() ||
            real_envido.pressed() ||
            falta_envido.pressed() )
        {
            if (envido.pressed())
            {
                envido.disabled();
                envido.mostrar(76, 590);
                case_envido = 0;
                envido.setUsed(true);
            }
            if (real_envido.pressed())
            {
                envido.disabled();
                envido.mostrar(76, 590);
                real_envido.disabled();
                real_envido.mostrar(227, 590);
                case_envido = 2;
                real_envido.setUsed(true);
            }

            if(falta_envido.pressed())
            {
                envido.disabled();
                envido.mostrar(76, 590);
                real_envido.disabled();
                real_envido.mostrar(227, 590);
                falta_envido.disabled();
                falta_envido.mostrar(378, 590);
                case_envido = 3;
                falta_envido.setUsed(true);
            }

            canto_envido = true;

            if( com_decidir_envido() == 2 )
            {
                quiereEnvido.mostrar(420, 258);
                noQuiereEnvido.mostrar(420, 458);

                while(true)
                {
//                    if(mouseCommandEnvido() != 2)
//                        break;

                    if( case_envido == 1 )
                    {
                        if (real_envido.pressed())
                        {
                            case_envido = 2;
                            real_envido.setUsed(true);
                            real_envido.disabled();
                            real_envido.mostrar(227, 590);

                            com_decidir_envido();
                        }

                        if(falta_envido.pressed())
                        {
                            case_envido = 3;
                            falta_envido.setUsed(true);
                            falta_envido.disabled();
                            falta_envido.mostrar(378, 590);

                            real_envido.setUsed(true);
                            real_envido.disabled();
                            real_envido.mostrar(227, 590);

                            com_decidir_envido();
                        }
                    }

                    if(case_envido == 2)
                    {
                        real_envido.setUsed(true);
                        real_envido.disabled();
                        real_envido.mostrar(227, 590);

                        if(falta_envido.pressed())
                        {
                            case_envido = 3;
                            falta_envido.setUsed(true);
                            falta_envido.disabled();
                            falta_envido.mostrar(378, 590);

                            com_decidir_envido();
                        }

                    }

                    if(case_envido == 3)
                    {
                        real_envido.setUsed(true);
                        real_envido.disabled();
                        real_envido.mostrar(227, 590);

                        falta_envido.setUsed(true);
                        falta_envido.disabled();
                        falta_envido.mostrar(378, 590);

                    }

                    if(mouseCommandEnvido() != 2)
                        break;
                }

    //         if(quiereEnvido.pressed())
    //           if(com_decidir_envido() != 0 && com_decidir_envido() != 1)
    //               if(quiereEnvido.pressed())
    //                   puntos_player += puntosEnvido;
            }

    //           continue;
        }
    }
}
int clsBaraja::jugar_truco()
{
    if( ! truco.get_used() &&
        ! re_truco.get_used() &&
        ! vale_4.get_used() )
        {
                if(truco.pressed())
                    {
                        calcularPuntosTruco(0);
                        truco.setUsed(true);
                        truco.disabled();
                        truco.mostrar(76, 666);
                        canto_truco = true;
                        return 0; // truco
                    }
        }

    if( ! re_truco.get_used() &&
        ! vale_4.get_used())
    {
        while(! re_truco.get_used())
        {
            if(re_truco.pressed())
                {
                    calcularPuntosTruco(1);
                    re_truco.setUsed(true);
                    re_truco.disabled();
                    re_truco.mostrar(76, 666);
                    canto_truco = true;
                    return 1; // re truco
                }
            if (mouseCommandTruco() != 1)
                break;
            else
                break;
        }

    }

    if( ! vale_4.get_used())
    {
        while(! vale_4.get_used())
        {
            if(vale_4.pressed())
            {
                calcularPuntosTruco(2);
                vale_4.setUsed(true);
                vale_4.disabled();
                vale_4.mostrar(76, 666);
                canto_truco = true;
                return 2; // vale 4
            }

            if (mouseCommandTruco() != 1)
                break;
            else
                break;
        }
    }
}


void clsBaraja::primera_ronda_player(int manoParaEnvido)
{
    while( true )
    {
        if(event->wasEvent())  //Verifico si hay evento
        {
            if(event->getEventType() == MOUSE_DOWN)  //Verifico si hay evento de teclado EventType()
            {
                if(guardarPartida.pressed())
                    break;

                if(abandonar.pressed())
                {
                    cout << "Se fue al mazo";
                    break;
                }

                if(carta_pressed(event->getCursorX(), event->getCursorY()))
                {
                    canto_envido = false;
                    canto_truco = false;
                    break;
                }

                jugar_envido();

                jugar_truco();
            }
        }
    }
    screen->refresh();
}
void clsBaraja::segunda_ronda_player()
{

}
void clsBaraja::tercera_ronda_player()
{

}


void clsBaraja::jugada_pj(int ron)
{
    switch(ron)
    {
        case 1:
            primera_ronda_player(ron);
        break;
        case 2:
            segunda_ronda_player();
        break;
        case 3:
            tercera_ronda_player();
        break;
        default:
            break;
    }
//    while( true )
//    {
//        if(event->wasEvent())  //Verifico si hay evento
//        {
//            if(event->getEventType() == MOUSE_DOWN)  //Verifico si hay evento de teclado EventType()
//            {
//                if(carta_pressed(event->getCursorX(), event->getCursorY()))
//                {
//                    canto_envido = false;
//                    canto_truco = false;
//                    break;
//                }
//
//                jugar_envido();
//
//                jugar_truco();
//
//                if(abandonar.pressed())
//                {
//                    break;
//                    cout << "Se fue al mazo";
//                }
//
//                if(guardarPartida.pressed())
//                    break;
//            }
//        }
//        screen->refresh();
//    }
}

int clsBaraja::mano(int vuelta)
{
    tantos_player = getTanto(cartas_player);
    tantos_com = getTanto(cartas_com);

    for (i = 1; i<4; i++)
    {
        manita = vuelta;

        if(i % 2)
        {
            if(i == 3 )
            {
                jugada_pj(i);
                refresh_screen(0);
                jugada_com(0);
                refresh_screen(0);
                cout<< "Tercera ronda\n";
                break;
            }

            if(i == 2)
            {
                jugada_com(1);
                refresh_screen(1);
                jugada_pj(i);
                refresh_screen(0);
                cout << "Segunda ronda\n";
                continue;
            }

            if(i == 1)
            {
                jugada_pj(i);
                refresh_screen(0);
                jugada_com(0);
                refresh_screen(1);
                cout << "primera ronda player mano\n";
                continue;
    //            envido.enabled();
    //            truco.enabled();
    //            envido.setButton(1);
    //            error.set(envido.setPath());
    //            if (error.get()) return error.get();
    //            envido.mostrar(60, 650);
            }
        // 10 = envido
        // 11 = envido envido
        // 12 = real envido
        // 13 = falta envido
        // 20 truco
        // 21 re truco
        // 22 vale 4truco.pressed();
//        i++;
        }
        else
        {
            if(i == 3)
            {
                jugada_pj(i);
                refresh_screen(0);
                jugada_com(1);
                refresh_screen(0);
                cout<< "tercera ronda\n";
                break;
            }

            if(i == 2)
            {
                jugada_com(0);
                refresh_screen(0);
                jugada_pj(i);
                refresh_screen(0);
                cout<< "segunda ronda\n";
                continue;
            }

            if(i == 1)
            {
                jugada_com(1);
                refresh_screen(0);
                jugada_pj(i);
                refresh_screen(0);
                cout<< "primera ronda com mano\n";
                continue;
            }

        }

//        ronda.init(carta_com_selected, carta_player_selected)



//        if (pj.get_event() == 1)
//            envido.set_envido();
//        abandonar.pressed();
//        carta_pressed(event->getCursorX(), event->getCursorY());
        screen->refresh();

//        // 0 = se fue al maso
//        if (pj.get_event() == 0)
//            break;
//        if (com.get_event() == 0)
//            break;
    }
}

void clsBaraja::calcularPuntosEnvido(int modoEnvido)
{
    switch(modoEnvido)
    {
    case 0:
        puntosEnvido = 2;
//        setPuntoEnvido(2);
        break;
    case 1:
        puntosEnvido += 2;
//        setPuntoEnvido(getPuntoEnvido() + 2);
        break;
    case 2:
        puntosEnvido += 3;
//        setPuntoEnvido(getPuntoEnvido() + 3);
        break;
    case 3:
        canto_falta_envido = true;
//        setPuntoEnvido(getPuntoEnvido() + 5);
        break;
    }
    cantos_envido++;
}

void clsBaraja::calcularPuntosTruco(int modoTruco)
{
    switch(modoTruco)
    {
    case 0:
        puntos_truco += 2;
        break;
    case 1:
        puntos_truco += 3;
        break;
    case 2:
        puntos_truco += 4;
        break;
    }
    cantos_truco++;
}

int clsBaraja::refresh_screen(int flag)
{
    screen->clean(BLACK);

    fondo.panio();
    envido.mostrar(76, 590);
    real_envido.mostrar(227, 590);
    falta_envido.mostrar(378, 590);

    truco.mostrar(76, 666);

    abandonar.mostrar(227, 666);

    guardarPartida.mostrar(1100, 50);

    texto.write("COM", 20, 10, screen->getPtr());
    texto.write("PLAYER", 130, 10, screen->getPtr());

    puntuacion_com.setPuntaje(puntos_COM);
    puntuacion_com.setPath();
    puntuacion_com.mostrar(20,50);

    puntuacion_player.setPuntaje(puntos_player);
    puntuacion_player.setPath();
    puntuacion_player.mostrar(150,50);

    mostrar_cartas(flag);
    mazo.mostrar_mazo(flag);

    screen->refresh();
}
void clsBaraja::juego()
{
    bool vuelta = true;
    int vuelta_mano = 0;

    while(vuelta)
    {
        darCartas();

        run(0);

        mano(vuelta_mano % 2);

        if(guardarPartida.pressed())
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
