/**
 * @file dictionary.h
 * @brief Archivo de especificación del TDA Dictionary
 * @author Adrián Jaén Fuentes
 * @author Javier Gómez López
 */

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include <set>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class Dictionary{
    /**
     * @page repDictionary Representación del TDA Dictionary
     *
     * @section invDictionary
     *
     * En nuestro Dictionary se mantienen un cojunto de palabras. Como
     * no estaremos interesados en almacenar las definicones, solo los términos,
     * usaremos un tipo de dato "set"
     *
     * @section faDictionary Función de abstracción
     *
     * fa: tipo_rep ----> Dictionary
     *     set<string> ----> dictionary
     *
     *     La estructura set<string> representa el Dictionary
     */

private:
    /**
     * @brief Set formado por las palabras del diccionario
     */
    set<string> words;

public:

    class iterator{

    private:
        set<string>::iterator it;

    public:
        /**
         * @brief Constructor de iterator por defecto
         */
        iterator(){}

        /**
         * @brief Constructor de iterator por copia
         * @param otro iterator a copiar
         */
        iterator(const set<string>::iterator& otro):it(otro){}

        /**
         * @brief Constructor de iterator por copia a otro dictionary::iterator
         * @param otro dictionary::iterator a copiar
         */
        iterator(const iterator& otro):it(otro.it){}

        /**
         * @brief Destructor por defecto
         */
        ~iterator(){}

        /**
         * @brief Sobrecarga del operador de asignacion
         * @param otro iterator que se copia
         */
        iterator& operator= (const set<string>::iterator& otro){
            it = otro;

            return *this;
        }

        /**
         * @brief Sobrecarga del operador de asignación
         * @param otro dictionary::iterator a copiar
         */
        iterator& operator=(const iterator& otro){
            it = otro.it;

            return *this;
        }

        /**
         * @brief Sobrecarga del operador de acceso
         * @return \<string> donde apunta el iterador
         */
        string operator*() const{
            return *it;
        }

        /**
         * @brief Sobrecarga del operador de incremento
         */
        iterator& operator++(){
            it++;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de decremento
         * @return
         */
        iterator& operator--(){
            it--;
            return *this;
        }

        iterator& operator++(int){
            it++;
            return *this;
        }

        iterator& operator--(int){
            it--;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de desigualdad
         * @param otro iterador a comparar
         * @return True si son distintos, false si son iguales
         */
        bool operator!= (const iterator& otro){
            return it != otro.it;
        }

        /**
         * @brief Sobrecarga del operador de igualdad
         * @param otro iterador a comparar
         * @return True si son iguales, false si son distintos
         */
        bool operator== (const iterator& otro){
            return it == otro.it;
        }
    };

    iterator begin(){
        iterator i = words.begin();
        return i;
    }

    iterator end(){
        iterator i = words.end();
        return i;
    }

    class const_iterator{
    private:
        set<string>::const_iterator it;

    public:

        const_iterator(){}

        const_iterator(const set<string>::const_iterator& otro):it(otro){}

        const_iterator(const const_iterator& otro):it(otro.it){}

        ~const_iterator(){}

        const_iterator& operator=(const set<string>::const_iterator& otro){
            it = otro;
            return *this;
        }

        const_iterator& operator=(const const_iterator& otro){
            it = otro.it;
            return *this;
        }

        string operator*() const{
            return *it;
        }

        const_iterator& operator++(){
            it++;
            return *this;
        }

        const_iterator& operator--(){
            it--;
            return *this;
        }

        const_iterator& operator++(int){
            it++;
            return *this;
        }

        const_iterator& operator--(int){
            it--;
            return *this;
        }

        bool operator!=(const const_iterator& otro){
            return it != otro.it;
        }

        bool operator==(const const_iterator& otro){
            return it == otro.it;
        }
    };

    /**
     * @brief Constructor por defecto.
     *
     * Crea un Dictionary vacío
     */
    Dictionary();

    /**
     * @brief Constructor de copia
     *
     * Crea un Dictionary con el mismo contenido que el que se pasa como argumento
     * @param other Dictionary que se quiere copiar
     */
    Dictionary(const Dictionary & other);

    /**
     * @brief Indica si una palabra está en el diccionario o no.
     *
     * Este método comprueba si una determinada palabra se enceuntra o no en el diccionario.
     * @param val La palabra que se quiere buscar.
     * @return Booleano indicando si la palabra existe o no en el diccioanrio
     */
    bool exists(const string &val) const;

    /**
     * @brief Inserta una palabra en el diccionario.
     * @param val Palabra a insertar en el diccionario
     * @return Booleano que indica si la insercción ha tenido éxito. Una palabra se inserta con éxito si no existía previamente en el diccionario.
     */
    bool insert(const string &val);

    /**
     * @brief Elimina una palabra del diccionario.
     * @param val Palabra a borrar del diccionario
     * @return Booleano que indica si la palabra se ha borrado del diccionario
     */
    bool erase(const string &val);

    /**
     * @brief Limpia el Dictionary
     *
     * Elimina todas las palabras contenidas en el conjunto
     */
    void clear();

    /**
     * @brief Comprueba si el diccionario está vacío.
     * @return True si el diccionario está vacío, false en caso contrario
     */
    bool empty();

    /**
     * @brief Tamaño del diccionario
     * @return Número de palabras guardadas en el diccionario
     */
    unsigned int size() const;

    /**
     * @brief Indica el número de apariciones de una letra
     * @param c letra a buscar
     * @return Un entero indicando el numero de aparaciones
     */
    int getOcurrences(const char c);

    /**
     * @brief Cuenta el total de letras de un diccionario.
     * @return Entero con el total de letras
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada.
     * @param length Longitud de las palabras buscadas
     * @return Vector de palabras con la longitud deseada
     */
    vector<string> wordsOfLength(int length);
};

#endif
