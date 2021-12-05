/**
 * @file bag.h
 * @brief Archivo de especificación del TDA Bag
 * @author Adrián Jaén Fuentes
 * @author Javier Gómez López
 */

#ifndef __BAG_H__
#define __BAG_H__

#include "vector"
#include "cstdlib"
#include <cstdio>
#include <random>
#include <ctime>
#include "chrono"

using namespace std;

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

template<class T>
class Bag {
    /**
     * @page repBag Representación del TDA Bag
     *
     * @section invBag
     *
     * Bag<T> es un contenedor que nos permite extraer y añadir elementos de forma aleatoria fácilmente hecha
     * a partir del vector
     *
     * @section faBag
     *
     * fa: tipo_rep ----> Bag<T>
     *     vector<T> ----> Bag<T>
     *
     *     La estructura representa el Bag
     */

private:
    vector<T> v;
public:

    /**
     * @brief Constructor base
     */
    Bag();

    /**
     * @brief Constructor de copia. Crea una copia exacta de otro objeto tipo Bag
     * @param other Objeto de tipo Bag<T> del que se va a realizar la copia
     */
    Bag(const Bag<T> &other);

    /**
     * @brief Añade un elemento a la bolsa
     * @param element elemento del tipo T a añadir a la bolsa
     */
    void add(const T &element);

    /**
     * @brief Extrae un elemento aleatorio de la bolsa
     * Devuelve un elemento aleatorio de la bolsa y lo elimina de la misma
     * @return Elemento de tipo T extraído de la bolsa
     * @pre La bolsa no está vacía
     * @post El elemento devuelto se ha eliminado de la bolsa
     */
    T get();

    /**
     * @brief Elimina todos los elementos de la bolsa
     * Borra todos los elementos almacenados en la bolsa
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa
     * @return Número de elemetos que hay en la bolsa
     */
    unsigned int size() const;

    /**
     * @brief Comprueba si la bolsa está vacía
     * @return true si la bolsa está vacía, false en caso contrario
     */
    bool empty();

    /**
     * @brief Sobrecarga el operador de asignación
     * @param other Bag<T> a copiar
     * @return Referencia a this para poder encadenar el operador
     */
    Bag<T>& operator=(const Bag<T> &other);

};

#endif //__BAG_H__


