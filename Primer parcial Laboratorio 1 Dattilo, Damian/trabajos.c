#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajos.h"
#include "bicicletas.h"
#include "validaciones.h"


int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int error=1;

    if(trabajos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            trabajos[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}

int altaTrabajo(eTrabajo trabajos[], int tamTrab, int idTrab, int max)
{
    int index;
    int error=1;

    if(trabajos!=NULL && tamTrab>0 && idTrab>=1000)
    {
        index = buscarTrabajoLibre(trabajos, tamTrab);
        if(index == -1)
        {
            printf("\nArreglo completo!\n\n");
        }
        else
        {
            trabajos[index].id = idTrab;

            printf("\nIngrese id de la bici: ");
            scanf("%d", &trabajos[index].idBici);

            while(validarIdBici(trabajos[index].idBici, max)==1)
            {
                printf("\nERROR Ingrese nuevamente\n");
                printf("\nIngrese id de la bici: ");
                scanf("%d", &trabajos[index].idBici);
            }

            printf("Ingrese id del servicio: ");
            scanf("%d", &trabajos[index].idServicio);
            while(validarIdServicio(trabajos[index].idServicio)==1)
            {
                printf("\nERROR Ingrese nuevamente\n");
                printf("\nIngrese id del servicio: ");
                scanf("%d", &trabajos[index].idServicio);
            }

            printf("\nIngrese fecha del trabajo: ");
            scanf("%d/%d/%d", &trabajos[index].fecha.dia, &trabajos[index].fecha.mes, &trabajos[index].fecha.anio);

            trabajos[index].isEmpty=0;

            error = 0;
        }
    }

    return error;
}

int buscarTrabajoLibre(eTrabajo trabajos[], int tam)
{
    int indice=-1;//Dentro del tamaño de la funcion el indice puede ser 0 o mayor
    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty==1)//Cuando el valor de i sea ==1(lugar vacio) indice va a valer la direccion vacia del vector
        {
            indice=i;
            break;
        }
    }
    return indice;//retorna el valor del indice vacio en el vector
}

int mostrarTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServ)
{
    int error=1;
    int flag=0;

    if(trabajos!= NULL && tam > 0)
    {
        printf("\nId       Id Bici   Fecha       Servicio\n");
        printf(" ----------------------------------------------\n");
        for(int i=0; i<tam; i++)//analiza el tamaño del vector
        {
            if(trabajos[i].isEmpty==0)// Si isEmpty dentro del vector es 0 entonces muestra la funcion mostrar persona
            {
                mostrarTrabajo(trabajos[i], servicios, tamServ);
                flag=1;//Si encuentra datos cargados en la lista el valor de la flag es 1
            }
        }
        printf("\n\n");
        if(flag==0)
        {
            printf("    No hay trabajos en la lista\n\n");
        }
        error= 0;//Una vez verificado que sea un vector de tamaño mayor a 0 devuelvo 0 errores
    }

    return error;
}


void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamServ)
{
    char desc[20];

    cargarDescripcionServicio(unTrabajo.idServicio, servicios, tamServ, desc);

    printf(" %4d   %4d     %d/%d/%d       %s\n", unTrabajo.id, unTrabajo.idBici, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio, desc);//Imprime los datos de la persona segun su posicion en el vector
}

void cargarDescripcionServicio(int idServicio, eServicio servicios[], int tamServ, char desc[])
{
    for(int i=0;i<tamServ;i++)
    {
        if(servicios[i].id==idServicio)
        {
            strcpy(desc, servicios[i].descripcion);
            break;
        }

    }
}

int mostrarServicios(eServicio array[],int tam)
{
    int retorno=-1;

    if(array != NULL && tam > 0)
    {
       printf("\n***LISTA DE SERVICIOS***\n");
        printf("ID    DESCRIPCION    PRECIO\n");
        printf("---------------------------\n");
        for(int i=0;i<tam;i++)
        {
            mostrarServicio(array[i]);
        }

    }


    return retorno ;

}
void mostrarServicio(eServicio unServicio)
{

    printf("%d   %s      %d\n", unServicio.id, unServicio.descripcion, unServicio.precio);

}
