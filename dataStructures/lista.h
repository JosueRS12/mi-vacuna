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
  
  Nodo<T> *getHead(); 
  void setHead(Nodo<T> *); 
  bool listaVacia(); //
  int tamLista(); //
  T obtenerDato(T); // 
  bool existe(T);
  bool eliminar(int pos); // 
  void insertarInicio(T infoNueva); //
  void insertarPos(T infoNueva, int pos);
  bool modificar(T, int pos);
};

template <class T>
void Lista<T> :: setHead(Nodo<T> *p){
  this->head = p;
} 

template <class T>
Nodo<T> *Lista<T> :: getHead(){
  return head;
} 

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
T Lista<T> :: obtenerDato(T inf){
  Nodo<T> *nodo = head;
  while(nodo != NULL){
    if(nodo->info = inf)
      return nodo->info; //nodo->info => persona.get()
    nodo = nodo -> sig;
  }
  return NULL;
} 

template <class T>
bool Lista<T> :: existe(T inf){
  Nodo<T> *nodo = head;
  while(nodo != NULL){
    if(nodo->info = inf)
      return true;
    nodo = nodo -> sig;
  }
  return false;
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
