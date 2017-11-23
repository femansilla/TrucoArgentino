#include "clsMotor.h"

int clsMotor::init()
{
    error.set(0);

    error.set(mode.init(DEFAULT));
    if (error.get()) return error.get();

    error.set(screen.init( 1280, //mode.getScrWidth(),
                          710,//mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          AUTODETECT
                          ));
    if (error.get()) return error.get();

    error.set(presentacion.init(&screen, &event));
    if (error.get()) return error.get();

//    error.set(juego.init(&screen, &event));
//    if (error.get()) return error.get();
//    armar_escala();


//    mezclar();

//    error.set(texto.init());
//    if (error.get()) return error.get();

    screen.setTitle("Truco");

    return error.get();
}

int clsMotor::run()
{
    error.set(0);

    error.set(presentacion.run());
    if (error.get()) return error.get();

    bool salir = false;

    //screen.refresh();

//    error.set(juego.run());
//    if (error.get()) return error.get();

//    screen.refresh();

//    while(!salir)  //Ciclo del programa
//    {
//        if(event.wasEvent())  //Verifico si hay evento
//        {
//            if(event.getEventType() == MOUSE_DOWN)  //Verifico si hay evento de teclado EventType()
//            {
////                if (baraja.carta_pressed(event.getCursorX(), event.getCursorY()))
////                {
////                    baraja.tira_com();
////
////                    if (comparar_cartas(baraja.get_carta_player(), baraja.get_carta_com()) == 1)
////                        cout<<"gane yo";
////                    else
////                    {
////                        if(comparar_cartas(baraja.get_carta_player(), baraja.get_carta_com()) == -1)
////                            cout<<"te gane";
////                        else
////                        {
////                            cout<<"que gane la mejor";
////                        }
////
////                    }
//
////                }
//            }
//        }
//    }


//    error.set(texto.loadFont("FONTS/Griffy-Regular.ttf", 52));
//    if (error.get()) return error.get();
//
//    screen.clean(LIGHTBLUE);
//    texto.setFontColor(BLACK);
//    texto.centredWrite("MENU PRINCIPAL", 100, screen.getPtr());
//    texto.centredWrite("jugar", 150, screen.getPtr());
//    texto.centredWrite("ayuda", 210, screen.getPtr());
//    texto.centredWrite("salir", 270, screen.getPtr());
//

    return error.get();
}

//int clsMotor::comparar_cartas(clsCarta cartaPJ, clsCarta cartaCOM)
//{
//
//    if(devolver_altura(cartaPJ) > devolver_altura(cartaCOM))
//        return 1;
//    else
//    {
//        if(devolver_altura(cartaPJ) < devolver_altura(cartaCOM))
//            return -1;
//        else
//            return 0;
//    }
//}
//
//int clsMotor::devolver_altura(clsCarta carta)
//{
//    for(int f=0; f<14; f++)
//    {
//        for(int c=0; c<4; c++)
//        {
//            escala[f][c].init(&screen, &event);
//
//            if(match_carta(escala[f][c], carta ))
//                return f;
//        }
//    }
//}
//
//bool clsMotor::match_carta(clsCarta carta_escala, clsCarta carta_juego)
//{
//    if(carta_escala.getNumero() == carta_juego.getNumero() &&
//       strcmp(carta_escala.getPalo(), carta_juego.getPalo()))
//    {
//        cout<< "carta match"<<endl;
//        return true;
//    }
//
//    else
//        return false;
//}
