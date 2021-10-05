#ifndef MINISTERIO_H
#define MINISTERIO_H
#include <iostream>
#include <cstdlib>
#include <wchar.h>
#include <stdio.h>
#include "../models/Persona.h"
#include "../dataStructures/multilista.h"
#include "../dataStructures/arbolesRN.h"
#include "../dataStructures/pila.h"
#include <string>

using namespace std;


int menuMinisterio(){
  int op;
  cout<<"¿Qué operación desea realizar?"<<endl;
  cout<<"1) Simulación"<<endl;
  cout<<"2) consultas"<<endl;
  cout<<"3) Salir"<<endl;
  cin>> op;
  cin.ignore();
  return op;
}


//void insertarPersonita(Persona delSenior);
Multilista *simulacion(ARBOL<int,Persona> *p){
  Pila<Persona> *pila = p->obtenerPila(p->raiz_arbol());
  Multilista *multiPersona = NULL;
  while(pila->pilaVacia()==false){ //se genera la multilista
    multiPersona->insertarPersonita(pila->pop());
  }
  return multiPersona; //...
}

void consultas(){
  Date date; 
  int op;
  string readStr;
  cout<<"¿Qué desea consultar"<<endl;
  cin>>op;
  cin.ignore();
  switch (op){
    case 1:
      {

      }break;
    case 2:
      {

      }break;
    case 3:
      {

      }break;
    case 4:
      {

      }break;
    case 5:
      {

      }break;
    case 6:
      {

      }break;
    case 7:
      {

      }break;
    default:
      cout<<"vuelva pronto"<<endl;
      break;
  }
}
#endif
