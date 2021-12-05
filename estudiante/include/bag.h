//
// Created by Adrián Jaén on 04/12/2021.
//

#ifndef __BAG_H__
#define __BAG_H__

#include "vector"
#include "cstdlib"
#include "stdio.h"
#include <random>
#include <time.h>
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
    unsigned int size() const;

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


template<class T>
Bag<T>::Bag(){
    this->v=vector<T>{};
}

template<class T>
Bag<T>::Bag(const Bag<T> &other) {
    this->v = other.v;
}

template<class T>
void Bag<T>::add(const T &element) {
    if (v.size() == 0)
        v.push_back(element);
    else {
        srand (1);
        int randNum = rand()%v.size();
        v.push_back(v[randNum]);
        v[randNum] = element;
    }
}

template<class T>
T Bag<T>::get() {
    srand (time(NULL));
    int randNum = rand()%v.size();
    T element = v[randNum];
    v[randNum] = v[v.size()-1];
    v.pop_back();
    return element;
}

template<class T>
void Bag<T>::clear() {
    v.clear();
}

template<class T>
unsigned int Bag<T>::size() const {
    return v.size();
}

template<class T>
bool Bag<T>::empty() {
    return v.empty();
}

template<class T>
Bag<T> &Bag<T>::operator=(const Bag<T> &other) {
    v = other.v;
    return *this;
}

#endif //__BAG_H__
