#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"
#include "validaciones.h"
#include "informes.h"
// 1ER PARCIAL 2 CUATRIMESTRE
#define TAM 1000
#define TAMCOL 5
#define TAMTIPO 4
#define TAMSERV 4
#define TAMTRAB 1000

char imprimirMenu();




int main()
{
    eBici listaBicis[TAM];
    eTrabajo listaTrabajos[TAMTRAB];

    int proximoId=1000;
    int proximoIdTrabajo=1000;
    char salir = 'n';
    int flagAlta=1;
    int flagTrabajo=1;
    int rta;
    //int opcionInformes;
    int ascendenteT;
    int ascendenteR;

    eColor colores[TAMCOL] = {
    {5000, "Gris"},
    {5001, "Negro"},
    {5002, "Blanco"},
    {5003, "Azul"},
    {5004, "Rojo"}
    };

    eTipo tipos[TAMTIPO] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002,"Mountain"},
        {1003,"BMX"},
    };

    eServicio servicios[TAMSERV] = {

    {20000, "Limpieza", 250},
    {20001, "Parche", 300},
    {20002, "Centrado", 400},
    {20003, "Cadena", 350},

    };

    if(!inicializarBicis(listaBicis, TAM))
    {
        printf("Bicicletas inicializadas con exito!!!\n\n");
    }
    else
    {
        printf("Problemas al inicializar bibicletas....\n\n");
    }

    if(!inicializarTrabajos(listaTrabajos, TAMTRAB))
    {
        printf("Trabajos inicializados con exito!!!\n\n");
    }
    else
    {
        printf("Problemas al inicializar trabajos....\n\n");
    }


    proximoId+= hardcodearBicis(listaBicis, TAM, 5);
    do
    {
        switch(imprimirMenu())
        {
        case 'a':
            if(!altaBici(listaBicis, TAM, proximoId, tipos, TAMTIPO, colores, TAMCOL))
            {
                printf("\nAlta exitosa\n\n");
                proximoId++;
                flagAlta=1;
            }
            else
            {
                printf("\nERROR al inicializar\n\n");
            }
            break;
        case 'b':
            if(!flagAlta)
            {
                printf("\nERROR, debe hacer al menos un alta\n\n");
            }
            else
            {
                if(!modificarBici(listaBicis, TAM, tipos, TAMTIPO, colores, TAMCOL))
                {
                    printf("\nModificacion exitosa\n\n");
                }
                else
                {
                    printf("\nFallo en la modificacion\n\n");
                }
            }
            break;
        case 'c':
            rta=bajaBici(listaBicis, TAM, tipos, TAMTIPO, colores, TAMCOL);
            if(rta==0)
            {
                printf("\nBaja exitosa\n\n");
            }
            else if(rta==2)
            {
                printf("\nBaja cancelada por el usuario\n\n");
            }
            break;
        case 'd':
            system("cls");

            printf("Desea tipo ascendente (1) o descendente (0): ");
            scanf("%d", &ascendenteT);
            while(ascendenteT!= 1 && ascendenteT!=0)
            {
                printf("\nERROR, ingrese nuevamente: ");
                scanf("%d", &ascendenteT);
            }

            printf("\nDesea rodado ascendente (1) o descendente (0): ");
            scanf("%d", &ascendenteR);
            while(ascendenteR!= 1 && ascendenteR!=0)
            {
                printf("\nERROR, ingrese nuevamente: ");
                scanf("%d", &ascendenteR);
            }

            ordenarBicis(listaBicis, TAM, tipos, TAMTIPO, ascendenteT, ascendenteR);

            system("cls");
            mostrarBicis(listaBicis, TAM, tipos, TAMTIPO, colores, TAMCOL);
            break;
        case 'e':
            system("cls");
            mostrarTipos(tipos, TAMTIPO);
            printf("\n\n");
            break;
        case 'f':
            system("cls");
            mostrarColores(colores, TAMCOL);
            printf("\n\n");
            break;
        case 'g':
            system("cls");
            mostrarServicios(servicios, TAMSERV);
            printf("\n\n");
            break;
        case 'h':
            if(flagAlta==1 && !altaTrabajo(listaTrabajos, TAMTRAB, proximoIdTrabajo, proximoId))
            {
                printf("\nAlta exitosa\n\n");
                flagTrabajo=1;
                proximoIdTrabajo++;
            }
            else if(flagAlta==0)
            {
                printf("\nERROR Debe realizar al menos un alta de bici\n\n");
            }
            else
            {
               printf("\nError al realizar el alta\n\n");
            }
            break;
        case 'i':
            if(flagTrabajo==0)
            {
                printf("\nERROR Debe realizar al menos un alta de trabajo\n\n");
            }
            else
            {
                mostrarTrabajos(listaTrabajos, TAMTRAB, servicios, TAMSERV);
                printf("\n\n");
            }
            break;
        case 'j':
            system("cls");
            menuInformes(listaBicis, TAM, listaTrabajos, TAMTRAB, tipos, TAMTIPO, colores, TAMCOL, servicios, TAMSERV);

            break;
        case 'k':
            printf("Confirma salida? ");
            do
            {
                fflush(stdin);
                scanf("%c", &salir);
                salir=tolower(salir);
                while(salir!='s' && salir!='n')
                {
                    printf("\nERROR Ingrese nuevamente: ");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir=tolower(salir);
                }
            }while(salir!='s' && salir!='n');
            break;
        }
        system("pause");
        system("cls");
    }while(salir!='s');

    return 0;
}

char imprimirMenu()
{
    char opcion;

    printf("***** MENU *****\n\n");
    printf("A_Alta Bicicleta\n");
    printf("B_Modificar Bicicleta\n");
    printf("C_Baja Bicicleta\n");
    printf("D_Listar Bicicletas\n");
    printf("E_Listar Tipos\n");
    printf("F_Listar Colores\n");
    printf("G_Listar Servicios\n");
    printf("H_Alta Trabajo\n");
    printf("I_Listar Trabajos\n");
    printf("J_Informes\n");
    printf("K_Salir\n\n");

    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);
    while(opcion<97 || opcion>107)
    {
        printf("\nERROR Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);
    }

    return opcion;
}

