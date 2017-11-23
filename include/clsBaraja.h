#ifndef CLSBARAJA_H
#define CLSBARAJA_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsCarta.h>
#include <clsMaso.h>
#include <clsRandom.h>
#include <stdio.h>
#include<stdlib.h>
#include <clsTimer.h>
#include <clsRonda.h>
#include <clsButton.h>
#include <clsFondo.h>
#include <clsPuntos.h>
#include <clsMensajes.h>
#include <clsGuardarPartida.h>

class clsBaraja
{
   private:
        clsEvent *event;
        clsScreen *screen;
        clsError error;
        clsRandom random;
        clsTimer tiempo;
        clsFondo fondo;

        clsMaso mazo;
        clsCarta cartas_player[3];
        clsCarta cartas_com[3];
        clsCarta carta_player_selected;
        clsCarta carta_com_selected;

        clsRonda ronda;

        int i;

        int puntos_COM = 0;
        int puntos_player = 0;
        int puntosEnvido = 0;

        int tantos_com;
        int tantos_player;
        int envido_quiere;

        int case_envido = 0;
        int cantos_envido;
        bool canto_envido;
        bool canto_falta_envido;

        bool canto_truco;

        int parda_index_mata, parda_index_tira = 0;
        int jugada_index_mata, jugada_index_tira = 0;

        int manita = 0;

        clsButton envido;
        clsButton envido_envido;
        clsButton real_envido;
        clsButton falta_envido;
        clsButton quiereEnvido;
        clsButton noQuiereEnvido;

        clsButton truco;
        clsButton re_truco;
        clsButton vale_4;
        clsButton quiereTruco;
        clsButton noQuiereTruco;

        clsButton abandonar; // al mazo

        clsButton guardarPartida;

        clsMensajes mensaje;

        clsCarta escala[14][4];

        int sel[12] = {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, *ptrSel = sel;

    public:
        ~clsBaraja();

        int init(clsScreen *, clsEvent */*, clsCarta[][4]*/);
        int run(int);

        void mezclar();
        int darCartas();

        void mostrar_cartas(int);
        void mostrar_cartas_player(int);
        void mostrar_cartas_com(int);

        bool carta_pressed(int, int);

//        int getPuntoEnvido(){return puntosEnvido;}
//        void setPuntoEnvido(int value){ puntosEnvido = value; }
        int getTanto(clsCarta[3]);

        clsCarta tira_com();
        void jugada_com(int);

        int pensar();

        int mano(int);

        bool regla_envido();
        bool parda(clsCarta);

        int get_grupo_escala(clsCarta);
        clsCarta buscar_menor();

        int contar_cartas( clsCarta );

        void calcularPuntosEnvido(int );

        int com_decidir_envido();

        void jugada_pj(int);

        void jugar_envido();
        void comparar_tantos();
        void re_envido(int);

        clsButton getGuardarpartida() {return guardarPartida;}

        int mouseCommand();
        int refresh_screen(int);

};

#endif // CLSBARAJA_H
