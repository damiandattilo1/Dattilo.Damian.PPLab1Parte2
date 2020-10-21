#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include "dataStore.h"
#include "bicicletas.h"
#include "trabajos.h"
#include "validaciones.h"

int validarTipo (int valor)
{
    int ok=1;
    if(valor>=1000 && valor<=1003)
    {
        ok=0;
    }

    return ok;
}

int validarColor (int valor)
{
    int ok=1;
    if(valor>=5000 && valor<=5004)
    {
        ok=0;
    }

    return ok;
}

int validarIdBici(int valor, int max)
{
    int ok=1;
    if(valor>=1000 && valor<max)
    {
        ok=0;
    }
    return ok;
}

int validarIdServicio(int valor)
{
    int ok=1;
    if(valor>=20000 && valor<20003)
    {
        ok=0;
    }
    return ok;
}
