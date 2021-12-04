//
// Created by Adrián Jaén on 04/12/2021.
//

#ifndef __BAG_H__
#define __BAG_H__

#include "vector"
using namespace std;

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

template<class T>
class Bag {

private:
    vector<T> v;
public:

    /**
     * @brief Base constructor
     */
    Bag();

    /**
     * @brief Constructor de copia. Crea una copia exacta de otro objeto tipo Bag
     * @param other Objeto de tipo Bag<T> del que se va a realizar la copia
     */
    Bag(const Bag<T> &other);

    /**
     *
     * @param element
     */
    void add(const T &element);

    /**
     *
     * @return
     */
    T get();

    /**
     *
     */
    void clear();

    /**
     *
     * @return
     */
    unsigned int size();

    /**
     *
     * @return
     */
    bool empty();

    /**
     *
     * @param other
     * @return
     */
    Bag<T>& operator=(const Bag<T> &other);

};

#endif //__BAG_H__
