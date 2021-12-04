//
// Created by Adrián Jaén on 04/12/2021.
//

#include "bag.h"
#include <random>

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
        int randNum = rand()%v.size();
        v.push_back(v[randNum]);
        v[randNum] = element;
    }
}

template<class T>
T Bag<T>::get() {
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
unsigned int Bag<T>::size() {
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