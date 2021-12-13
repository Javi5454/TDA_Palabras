/**
 *   \file solver.h
 *   \brief Archivo de declaración de la clase Solver
 */
//
// Created by Adrián Jaén on 12/12/2021.
//

#ifndef P04_TDAS_NO_LINEALES_SOLVER_H
#define P04_TDAS_NO_LINEALES_SOLVER_H

#include "dictionary.h"
#include "letters_set.h"

class Solver {


private:
    Dictionary dict;
    LettersSet letters_set;


    /**
     * @brief Comprueba si una palabra se puede construir a partir de un conjunto de
     * letras dado
     * @param available_letters Vector de letras disponibles
     * @param word Palabra a comprobar
     * @return True si la palabra se puede construir, False si no se puede consturir
     */
    bool possibleSol(vector<char> available_letters, const string &word);

    /**
     * @brief Crea un diccionario formado solo por palabras ya válidas a partir de unas
     * letras disponibles.
     * @param available_letters Vector de letras disponibles
     * @return Diccionario que contine solo las palabras que podemos formar a partir de
     * las letras dadas en \<available_letters>.
     */
    Dictionary possibleWords(const vector<char>& available_letters);

    /**
     * @brief Construye un vector de las posibles soluciones de una partida por longitud.
     * Junto al vector va asociado un entero que indica la longitud de dichas palabras
     * @param dict Diccionario que contiene exclusivamente palabras que se pueden formar
     * a partir de las letras de nuestra partida
     * @return Par \<vector\<string>, int> con el vector de las palabras que son posibles
     * soluciones de nuestra partida, y su longitud.
     */
    pair<vector<string>, int> solveLongest(const Dictionary &dict);
public:

    /**
     * @brief Constructor con parámetros que crea un solver que tiene asociado un Dictionary u un LettersSet
     * @param dict
     * @param letters_set
     */
    Solver(const Dictionary& dict, const LettersSet& letters_set);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una partida.
     * Dado un conjunto de letras posibles para crear una solución, y el modo de juego con el que se juega la partida,
     * se construye un vector con las mejores soluciones encontradas en función del tipo de juego planteado.
     * @param available_letters Vector de letras disponibles para la partida
     * @param score_game Bool indicando el tipo de partida. True indica que la partida se juega a puntuación, false
     * que se juega a longitud
     * @return Par <vector<string>, int>, con el vector de palabras que constituyen las mejores funciones (puede haber
     * empates) y la puntuación que obtienen
     */
    pair<vector<string>, int>getSolutions(const vector<char> & available_letters, bool score_game);



};


#endif //P04_TDAS_NO_LINEALES_SOLVER_H
