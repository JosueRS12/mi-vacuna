#ifndef LISTA_H
#define LISTA_H

#include <cstdlib>
#include <iostream>
using namespace std;


template <class T>
struct Nodo{
  T info;
  Nodo<T>  *sig;
};

template <class T>
class Lista{
  //atributos
  Nodo<T> *head; 
  int tam;
  //constructor
  public:
  Lista(){
    head = NULL;
    tam = 0;
  }
  //metodos
  bool listaVacia(); //
  int tamLista(); //
  T obtenerDato(int pos); // 
  bool eliminar(int pos); // 
  void insertarInicio(T infoNueva); //
  void insertarPos(T infoNueva, int pos);
  bool modificar(T, int pos);
};

template <class T>
bool Lista<T> :: listaVacia(){
  if(tam == 0){
    return true;
  } 
  else {
    return false;
  }
}

template <class T>
int Lista<T> :: tamLista(){
  return tam; 
}

template <class T>
T Lista<T> :: obtenerDato(int pos){
  Nodo<T> *nodo = head;
  for(int i = 0; i<pos; i++){
    nodo = nodo -> sig; 
  }
  return nodo -> info; //
} 

template <class T>
bool Lista<T> :: eliminar(int pos){
  Nodo<T> *nodo = head;
  int i = 0;  
  if(pos==0){
    head = nodo -> sig;
    delete nodo;
    tam--;
    return true;
  }
  else if(pos<tam){
    while(i<(pos-1)){
      nodo = nodo -> sig; //anterior
      i++;
    }
    nodo -> sig = nodo -> sig -> sig;
    delete nodo -> sig;
    tam--;
    return true;
  }
  return false;
}

template <class T>
void Lista<T> :: insertarInicio(T infoNueva){
  Nodo<T> *nodo = new Nodo<T>; //funciona
  nodo -> info = infoNueva;
  nodo -> sig = head;
  head = nodo;
  tam++;
}
#endif
