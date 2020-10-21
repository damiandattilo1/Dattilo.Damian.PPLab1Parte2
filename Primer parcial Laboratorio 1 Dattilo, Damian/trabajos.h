#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char descripcion[25];
	int precio;
}eServicio;

typedef struct
{
	int id;
	int idBici;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;


#endif // TRABAJOS_H_INCLUDED


/** \brief Inicializa un arreglo de trabajos
 *
 * \param arreglo
 * \param tamaño del arreglo
 * \return 1 si hubo un error, 0 si exitoso
 *
 */

int inicializarTrabajos(eTrabajo trabajos[], int tam);

/** \brief da de alta un elemento en un arreglo de trabajos
 *
 * \param arreglo
 * \param tamaño del arreglo
 * \return 1 si error, 0 si exitoso
 *
 */

int altaTrabajo(eTrabajo trabajos[], int tamTrab, int idTrab, int max);

/** \brief busca un elemento libre en un arreglo de trabajos
 *
 * \param arreglo
 * \param tamaño del arreglo
 * \return la posicion del elemento o -1 si arreglo completo
 *
 */

int buscarTrabajoLibre(eTrabajo trabajos[], int tam);

/** \brief imprime un arreglo de trabajos
 *
 * \param arreglo
 * \param tamaño del arreglo
 * \return -1 si error, o si OK
 *
 */

int mostrarTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServ);

/** \brief imprime un elemento de un arreglo de trabajos
 *
 * \param elemento
 *
 */

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamServ);

/** \brief imprime un arreglo de servicios
 *
 * \param arreglo
 * \param tamaño del arreglo
 * \return -1 si error, o si OK
 *
 */

int mostrarServicios(eServicio array[],int tam);

/** \brief imprime un elemento de un arreglo de servicios
 *
 * \param elemento
 *
 */

void mostrarServicio(eServicio unServicio);


void cargarDescripcionServicio(int idServicio, eServicio servicios[], int tamServ, char desc[]);







