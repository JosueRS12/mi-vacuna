
Personita Multilista :: existeActual(Persona persona){
  Personita vacio;
  vacio.p = NULL;
  headPersonitas = listaPersonitas.getHead();
  while(headPersonitas != NULL){
    if(headPersonitas->info.p == &persona) //(personita) persona == persona
      return headPersonitas->info; //before =>personita
    headPersonitas = headPersonitas -> sig;
  }
  return vacio;
}

bool Multilista :: eliminarPersonitaLista(Persona persona){
  Nodo<Personita> *anterior, *aux = listaPersonitas.getHead();
  headPersonitas = listaPersonitas.getHead();
  while(aux != NULL){
    if(aux->info.p == &persona){
      if(aux == headPersonitas){
        listaPersonitas.setHead(aux->sig);
      } else{
        anterior -> sig = aux-> sig;
      }
      return true;
    } 
    anterior = aux;
    aux = aux -> sig;
  }
  return false;
}

bool Multilista :: eliminar(Persona persona){
  Personita personitaActual = existeActual(persona), *auxSig, *auxAnterior;
   
  if(personitaActual.p!=NULL){
    //sexo
    if(personitaActual == listaSexo.oo)
    auxSig = personitaActual.sigSexo;
    auxAnterior = personitaActual.antSexo;

    personitaActual.antSexo = personitaActual.sigSexo;
    personitaActual.sigSexo.antSexo = personitaActual.antSexo;

    
    //edad
    //actividad
    //paisN
    //ciudadR
    //eps
  }
  eliminarPersonitaLista(persona);
}

//referencia main para usar un FilePersona
int main(){
  Persona pers, pers2;
  //StackList<Persona> pila;
  Pila<Persona> pila;
  //Persona *arr = new Persona[2];

  pers.setNombre("benito");
  pers.setApellido("camelas");
  pers.setNombreEps("fami");

  pers2.setNombre("ben");
  pers2.setApellido("came");
  pers2.setNombreEps("fa");


  pila.push(pers);
  pila.push(pers2);
  
  FilePersona file;
  //file.setPila(pila);
  file.create(pila);

  return 0;
}



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
  public: 
  Pila(){
    cab = new nodo<T>;
    cab->dato=NULL; //' '
    cab->sig=NULL;
  }
  void push(T v);
  T pop();
  bool pilaVacia();
  ~Pila();
};

template<class T>
void Pila<T>::push(T v){
     nodo<T> *t = new nodo<T>;
     t->dato=v; 
     t->sig=cab->sig;
     cab->sig= t;
     }

template<class T>
T Pila<T>::pop(){
     T x;
     nodo<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
}
     
template<class T>
bool Pila<T>::pilaVacia(){
  return cab->sig== NULL;
}

template<class T>
Pila<T>::~Pila(){
  nodo<T> *t=cab;
  while (t!=NULL){
    cab=t;
    t=t->sig;
    delete cab;
 }
}
#endif
