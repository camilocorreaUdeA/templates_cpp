#include<iostream>
using namespace std;

template<typename T>
class ArregloDinamico{
    int longit = 0, capacidad = 0;
    T *array = nullptr;
    void agregarMemoria(T dato);
    public:
    ArregloDinamico(int cap);
    ArregloDinamico(int longi, int cap);
    ArregloDinamico(const ArregloDinamico<T> &arr);
    ~ArregloDinamico();
    void operator=(const ArregloDinamico<T> &arr);
    int longitud();
    T& operator[](int pos);
    int posicionDe(T elem);
    bool estaVacio();
    void agregarAlFinal(T dato);
};

template<typename T>
ArregloDinamico<T>::ArregloDinamico(int cap){
    capacidad = cap;
    array = new T[capacidad];
    longit = 0;
}

template<typename T>
ArregloDinamico<T>::ArregloDinamico(int longi, int cap){
    capacidad = cap;
    array = new T[capacidad];
    longit = longi;
}

template<typename T>
ArregloDinamico<T>::ArregloDinamico(const ArregloDinamico<T> &arr){
    capacidad = arr.capacidad;
    longit = arr.longit;
    array = new T[capacidad];
    for(int i=0; i<longit; ++i)
        *(array + i) = *(arr.array + i);
}

template<typename T>
void ArregloDinamico<T>::operator=(const ArregloDinamico<T> &arr){
    capacidad = arr.capacidad;
    longit = arr.longit;
    array = new T[capacidad];
    for(int i=0; i<longit; ++i)
        *(array + i) = *(arr.array + i);
}

template<typename T>
int ArregloDinamico<T>::longitud(){
    return longit;
}

template<typename T>
ArregloDinamico<T>::~ArregloDinamico(){
    delete[] array;
}

template<typename T>
T& ArregloDinamico<T>::operator[](int pos){
    if(pos > longit){
        cout<<"Esta intentando acceder a una posicion por fuera del arreglo"<<endl;
        throw("Error!");
    }
    return array[pos];
}

template<typename T>
int ArregloDinamico<T>::posicionDe(T elem){
    for(int i=0; i<longit; ++i){
        if(elem == array[i])
            return i;
    }

    cout<<"El dato no esta en el arreglo!"<<endl;
    return -1;
}

template<typename T>
bool ArregloDinamico<T>::estaVacio(){
    if(longit > 0)
        return false;

    return true;
}

template<typename T>
void ArregloDinamico<T>::agregarMemoria(T dato){
    capacidad += 5;
    T* temporal = new T[capacidad];
    for(int i=0; i<longit; ++i)
        *(temporal + i) = *(array + i);
    *(temporal + longit) = dato;
    delete[] array;
    array = temporal;
    longit++;
}

template<typename T>
void ArregloDinamico<T>::agregarAlFinal(T dato){
    if((longit + 1) >= capacidad)
        agregarMemoria(dato);
    else{
        *(array + longit) = dato;
        longit++;
    }
}





