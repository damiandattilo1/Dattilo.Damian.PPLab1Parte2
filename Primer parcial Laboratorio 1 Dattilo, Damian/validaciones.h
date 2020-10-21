#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief valida el valor ingresado como Id tipo
 *
 * \param el valor ingresado
 * \return 1 si Id no valido, 0 si Id valido
 *
 */

int validarTipo (int valor);

/** \brief valida el valor ingresado como Id color
 *
 * \param el valor ingresado
 * \return 1 si Id no valido, 0 si Id valido
 *
 */

int validarColor (int valor);

/** \brief valida el valor ingresado como Id bicicleta
 *
 * \param el valor ingresado
 * \param valor maximo en el arreglo de bicis
 * \return 1 si Id no valido, 0 si Id valido
 *
 */

int validarIdBici(int valor, int max);

/** \brief valida el valor ingresado como Id servicio
 *
 * \param el valor ingresado
 * \return 1 si Id no valido, 0 si Id valido
 *
 */

int validarIdServicio(int valor);
