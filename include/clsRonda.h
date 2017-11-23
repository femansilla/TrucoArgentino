#ifndef CLSRONDA_H
#define CLSRONDA_H
#include <clsCarta.h>

class clsRonda
{
    public:
//        clsRonda(clsCarta, clsCarta);
//        clsRonda();

        clsCarta get_carta_com();
        clsCarta get_carta_player();

        int get_rondas_com();
        int get_rondas_pj();

        void set_rondas_com();
        void set_rondas_pj();

        int comparar_cartas();
        int get_altura(clsCarta);
        bool match_carta(clsCarta, clsCarta);

        void set_escala(clsCarta[][4]);

        ~clsRonda();

    private:
        int rondas_com;
        int rondas_pj;

        clsCarta carta_player;
        clsCarta carta_com;

        clsCarta escala[14][4];


};

#endif // CLSRONDA_H
