#include <cstdlib>
#include <iostream>

#ifndef PILA_H     
#define PILA_H    

template<class T>
struct nodo{
  T dato;
  nodo<T> *sig;
};


template<class T>
class Pila{
  nodo<T> *cab;
  int tam;
  public: 
  Pila(){
    cab = new nodo<T>;
    cab->sig=NULL; //primer elemento en cabeza
    tam = 0;
  }
  int getTam();
  void push(T v);
  T pop();
  bool pilaVacia();
};

template<class T>
int Pila<T>:: getTam(){
  return tam;
}

template<class T>
void Pila<T>::push(T v){
  nodo<T> *t = new nodo<T>;
  t->dato=v; 
  t->sig=cab->sig;
  cab->sig= t;
  tam++;
}

template<class T>
T Pila<T>::pop(){
     T x;
     nodo<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     tam--;
     return x;
}
     
template<class T>
bool Pila<T>::pilaVacia(){
  return cab->sig== NULL;
}

#endif
