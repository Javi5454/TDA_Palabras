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

        /**
         * @page repIteradorDictionary Representación de el iterator de la clase Dictionary
         */

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

    /**
     * @brief Iterador begin
     * @return Iterator begin de Dicitonary
     */
    iterator begin(){
        iterator i = words.begin();
        return i;
    }

    /**
     * @brief Iterador end
     * @return Iterator end de Dicitonary
     */
    iterator end(){
        iterator i = words.end();
        return i;
    }

    class const_iterator{

        /**
         * @page repConstIteratorDictionary Representacion del const_iterator de la clase Dictionary
         */
    private:
        set<string>::const_iterator it;

    public:
        /**
         * @brief Constructor de const_iterator por defecto
         */
        const_iterator(){}

        /**
         * @page Constructor de const_iterator por copia
         * @param otro const_iterator de set a copiar
         */
        const_iterator(const set<string>::const_iterator& otro):it(otro){}

        /**
         * @brief Constructor de const_iterator por copia
         * @param otro const_iterator de dictionary a copiar
         */
        const_iterator(const const_iterator& otro):it(otro.it){}

        /**
         * @brief Destructor por defecto
         */
        ~const_iterator(){}

        /**
         * @brief Sobrecarga del operador de asignación
         * @param otro set const_iterator a copiar
         */
        const_iterator& operator=(const set<string>::const_iterator& otro){
            it = otro;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de asignación
         * @param otro dictionary const_iterator a copiar
         */
        const_iterator& operator=(const const_iterator& otro){
            it = otro.it;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de acceso
         * @return String a donde apunta el const_iterator
         */
        string operator*() const{
            return *it;
        }

        /**
         * @brief Sobrecarga del operador de incremento
         */
        const_iterator& operator++(){
            it++;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de decremento
         * @return
         */
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

        /**
         * @brief Sobrecarga de operador de desigualdad
         * @param otro const_iterator a comparar
         * @return True si son distintos, false si son iguales
         */
        bool operator!=(const const_iterator& otro){
            return it != otro.it;
        }

        /**
         * @brief Sobrecarga del operador de igualdad
         * @param otro const_iterator a comparar
         * @return True si son iguales, false si son distintos
         */
        bool operator==(const const_iterator& otro){
            return it == otro.it;
        }
    };

    /**
     * @brief Acceso primer elemento del dictionary mediante iterador constante
     * @return const_iterator que apunta al primer elemento de el dictionary
     */
    const_iterator begin() const{
        const_iterator i = words.begin();
        return i;
    }

    /**
     * @brief Acceso a memoria inmediatamente después del último elemento del dictionary mediante interador constante
     * @return const_iterator que apunta a la posición de memoria inmediatamente continua a el último elemento del
     * dictionary
     */
    const_iterator end() const{
        const_iterator i = words.end();
        return i;
    }

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
    int getOcurrences(char c);

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
    vector<string> wordsOfLength(int length) const;
};

#endif
