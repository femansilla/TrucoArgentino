#include "clsGuardarPartida.h"

bool clsGuardarPartida::grabarEnDisco()
{
    bool grabo;
    FILE *p;
    p = fopen("EXEC/puntosFacil.dat", "wb");

    if( p == NULL ) return false;

    grabo=fwrite(this,sizeof *this, 1, p);
    fclose(p);

    return grabo;
}

bool clsGuardarPartida::leerDeDisco()
{
    FILE * p; bool leyo;
    p = fopen("EXEC/puntosFacil.dat", "rb");

    if(p==NULL) return false;

    fseek(p, sizeof *this *1, 0);

    leyo= fread(this,sizeof *this, 1, p);
    fclose(p);

    return leyo;
}
