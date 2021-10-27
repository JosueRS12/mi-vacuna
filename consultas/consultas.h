#ifndef CONSULTAS_H
#define CONSULTAS_H
#include "../dataStructures/lista.h"
#include "../models/Persona.h"


//Listado de los nombres y apellidos de aquellos que tienen un país de nacimiento dado, clasificándolos por ciudad de residencia y EPS a la que pertenecen.MINISTERIO
Lista<Persona> cruceListas(Lista<Persona> lista,Lista<Persona> lista2){
  Nodo<Persona> *p = lista2.getHead();
  Lista<Persona> response = Lista<Persona>(); 
  while(p!=NULL){
    if(lista.existe(p->info)){
      response.insertarInicio(p->info); 
    }
    p=p->sig;
  }
  return response; 
}

void mostrarVarios(Lista<Persona> lista){
  Nodo<Persona> *p = lista.getHead();
  while(p!=NULL){
    cout<<"***********"<<endl;
    cout<<p->info.getCiudadR()<<endl; 
    cout<<p->info.getTipoVacuna()<<endl; 
    p=p->sig;
    cout<<"***********"<<endl;
  }
}

void mostrarNombresApellidos(Lista<Persona> lista){
  Nodo<Persona> *p = lista.getHead();
  while(p!=NULL){
    cout<<p->info.getNombre()<<" "<<p->info.getApellido()<<endl; 
    p=p->sig;
  }
}


//eps y rango de edad
void consulta4(Lista<Persona> listaEps, int tamLista){ //lista rango 0, 1, 2, 3, 4 ...
  if(listaEps.tamLista() >= tamLista){
    cout<<"Tamaño: "<<listaEps.tamLista()<<endl;
  }
}





#endif
