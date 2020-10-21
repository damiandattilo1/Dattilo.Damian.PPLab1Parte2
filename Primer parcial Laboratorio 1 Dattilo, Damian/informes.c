#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "bicicletas.h"
#include "trabajos.h"
#include "validaciones.h"



/** \brief imprime el menu de informes
 *
 * \return la opcion elegida por el usuario
 *
 */
int imprimirMenuInformes();



int mostrarBiciXColor(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol);

int mostrarBiciXTipo(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol);


/** \brief procesa las opciones del menu de informes
 *
 * \param
 * \param
 *
 */
void menuInformes(eBici bicis[], int tamBici, eTrabajo trabajos[], int tamTrab, eTipo tipos[], int tamTipo, eColor colores[], int tamCol, eServicio servicios[], int tamServ);
int menorRodado(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol);
int contarColorTipo(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol);
void coloresElegidos(eBici bicis[], int tamBici, eColor colores[], int tamCol);

//---------------------------------------------------------------------------------------------------

void menuInformes(eBici bicis[], int tamBici, eTrabajo trabajos[], int tamTrab, eTipo tipos[], int tamTipo, eColor colores[], int tamCol, eServicio servicios[], int tamServ)
{
    char salir='n';
    do
    {
        switch(imprimirMenuInformes())
        {
        case 1:
            system("cls");
            mostrarBiciXColor(bicis, tamBici, tipos, tamTipo, colores, tamCol);
            break;
        case 2:
            system("cls");
            mostrarBiciXTipo(bicis, tamBici, tipos, tamTipo, colores, tamCol);
            break;

        case 3:
            system("cls");
            menorRodado(bicis, tamBici, tipos, tamTipo, colores, tamCol);
            break;
        case 4:

            break;
        case 5:
            system("cls");
            contarColorTipo(bicis, tamBici, tipos, tamTipo, colores, tamCol);
            break;
        case 6:
            system("cls");
            coloresElegidos(bicis, tamBici, colores, tamCol);
            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;

        case 11:
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
}



int mostrarBiciXColor(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol)
{
    int error=-1;
    int idColor;
    int flag=0; //Indica que hay al menos una bici con ese color
    if(bicis!=NULL && tipos!=NULL && colores!=NULL)
    {
        mostrarColores(colores, tamCol);
        printf("\n\nIngrese id color: ");
        scanf("%d", &idColor);
        while(validarColor(idColor)==1)
        {
            printf("\nERROR ingrese nuevamente: ");
            scanf("%d", &idColor);
        }

        printf("\n   Id         Marca          Tipo       Color     Rodado   \n");
        printf(" -----------------------------------------------------\n");

        for(int i=0; i<tamBici;i++)
        {
            if(bicis[i].idColor==idColor && bicis[i].isEmpty==0)
            {
                mostrarBici(bicis[i], tipos, tamTipo, colores, tamCol);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\nNo hay ninguna bicicleta con ese color\n");
        }
        printf("\n");
        error=0;
    }
    return error;
}

int mostrarBiciXTipo(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol)
{
    int error=-1;
    int idTipo;
    int flag=0; //Indica que hay al menos una bici con ese tipo
    if(bicis!=NULL && tipos!=NULL && colores!=NULL)
    {
        mostrarTipos(tipos, tamTipo);
        printf("\n\nIngrese id tipo: ");
        scanf("%d", &idTipo);
        while(validarTipo(idTipo)==1)
        {
            printf("\nERROR ingrese nuevamente: ");
            scanf("%d", &idTipo);
        }

        printf("\n   Id         Marca          Tipo       Color     Rodado   \n");
        printf(" -----------------------------------------------------\n");

        for(int i=0; i<tamBici;i++)
        {
            if(bicis[i].idTipo==idTipo && bicis[i].isEmpty==0)
            {
                mostrarBici(bicis[i], tipos, tamTipo, colores, tamCol);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\nNo hay ninguna bicicleta con ese tipo\n");
        }
        printf("\n");
        error=0;
    }
    return error;
}

int menorRodado(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol)
{
    int error=-1;
    eBici copiaBicis[tamBici];
    eBici aux;
    float menorRodado;
    if(bicis!=NULL && tipos!=NULL && colores!=NULL)
    {
        error=0;
        for(int i=0; i<tamBici; i++)
        {
            copiaBicis[i]=bicis[i];
        }

        for(int i=0; i<tamBici-1; i++)
        {

            for(int j=i+1; j<tamBici; j++)
            {
                if(copiaBicis[i].rodado > copiaBicis[j].rodado)
                {
                    aux=copiaBicis[i];
                    copiaBicis[i]=copiaBicis[j];
                    copiaBicis[j]=aux;
                }
            }
        }
        for(int i=0;i<tamBici;i++)
        {
            if(copiaBicis[i].isEmpty==0)
            {
                menorRodado=copiaBicis[i].rodado;
                break;
            }
        }

        system("cls");
        printf("Las bicis de menor rodado son:\n\n");
        printf("   Id         Marca          Tipo       Color     Rodado   \n");
        printf(" -----------------------------------------------------\n");
        for(int i=0;i<tamBici ;i++)
        {
            if((copiaBicis[i].isEmpty==0) && (copiaBicis[i].rodado== menorRodado))
            {
                mostrarBici(copiaBicis[i], tipos, tamTipo, colores, tamCol);
            }
        }
    }
    return error;
}

int contarColorTipo(eBici bicis[], int tamBici, eTipo tipos[], int tamTipo, eColor colores[], int tamCol)
{
    int error=-1;
    int idTipo;
    int idColor;
    int contador=0;

    if(bicis!=NULL && tipos!=NULL && colores!=NULL)
    {
        mostrarTipos(tipos, tamTipo);
        printf("\n\nSeleccione ID tipo: ");
        scanf("%d", &idTipo);
        while(validarTipo(idTipo)==1)
        {
            printf("\nERROR ingrese nuevamente: ");
            scanf("%d", &idTipo);
        }
        system("cls");
        mostrarColores(colores, tamCol);
        printf("\n\nSeleccione ID color: ");
        scanf("%d", &idColor);
        while(validarColor(idColor)==1)
        {
            printf("\nERROR ingrese nuevamente: ");
            scanf("%d", &idColor);
        }

        for(int i=0; i<tamBici;i++)
        {
            if(bicis[i].idTipo==idTipo && bicis[i].idColor==idColor)
            {
                contador++;
            }
        }
        system("cls");
        printf("Hay %d bicis con ese tipo y ese color\n\n", contador);
        error=0;
    }
    return error;
}

void coloresElegidos(eBici bicis[], int tamBici, eColor colores[], int tamCol)
{
    int gris=0;
    int negro=0;
    int blanco=0;
    int azul=0;
    int rojo=0;

        for(int i=0;i<tamBici;i++)
        {
            if(bicis[i].isEmpty==0)
            {
                if(bicis[i].idColor==5000)
                {
                    gris++;
                }
                else if(bicis[i].idColor==5001)
                {
                    negro++;
                }
                else if(bicis[i].idColor==5002)
                {
                    blanco++;
                }
                else if(bicis[i].idColor==5003)
                {
                    azul++;
                }
                else if(bicis[i].idColor==5004)
                {
                    rojo++;
                }
            }
        }


        printf("Los colores mas elegidos son:");

            if(gris>negro && gris>blanco && gris>azul && gris>rojo)
            {
                printf(" gris ");
            }
            if(negro>gris && negro>blanco && negro>azul && negro>rojo)
            {
                printf(" negro ");
            }
            if(blanco>negro && blanco>gris && blanco>azul && blanco>rojo)
            {
                printf(" blanco ");
            }
            if(azul>negro && azul>blanco && azul>gris && azul>rojo)
            {
                printf(" azul ");
            }
            if(rojo>negro && rojo>blanco && rojo>azul && rojo>gris)
            {
                printf(" rojo ");
            }

            printf("\n\n");


}

int imprimirMenuInformes()
{
    int opcion;

    printf("***** MENU INFORMES *****\n\n");
    printf("1_Mostrar bicis por color\n");
    printf("2_Mostrar bicis por tipo\n");
    printf("3_Bici(s) de menor rodado\n");
    printf("4_Mostrar bicis por tipo\n");
    printf("5_Contar bicis por color y tipo\n");
    printf("6_Colores mas elegidos\n\n");

    printf("7_Trabajos por bici\n");
    printf("8_ Suma importes\n");
    printf("9_Bicis por servicio\n");
    printf("10_Servicios por fecha\n");
    printf("11_Salir\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    while(opcion<1 || opcion>11)
    {
        printf("\nERROR Ingrese nuevamente: ");
        scanf("%d", &opcion);
    }

    return opcion;
}
