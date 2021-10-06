#ifndef MINISTERIO_H
#define MINISTERIO_H
#include <iostream>
#include <cstdlib>
#include <wchar.h>
#include <stdio.h>
#include <conio.h>
#include "../models/Persona.h"
#include "../dataStructures/multilista.h"
#include "../dataStructures/arbolesRN.h"
#include "../dataStructures/pila.h"
#include "../consultas/consultas.h"
#include <string>

using namespace std;


int menuMinisterio(){
  int op;
  system("clear");
  cout<<"------------MINISTERIO------------"<<endl;
  cout<<"¿Qué operación desea realizar?"<<endl;
  cout<<"1) Simulación"<<endl;
  cout<<"2) consultas"<<endl;
  cout<<"3) Salir"<<endl;
  cin>> op;
  cin.ignore();
  return op;
}


//void insertarPersonita(Persona delSenior);
Multilista *cargarMultilista(ARBOL<int,Persona> *p){
  Pila<Persona> *pila = p->obtenerPila(p->raiz_arbol());
  int tam = pila->getTam();
  Multilista *multiPersona = new Multilista(tam);
  int i = 0;
  while(pila->pilaVacia()==false){ //se genera la multilista
    multiPersona->insertarPersonita(pila->pop());
    i++;
  }
  return multiPersona; //...
}

void consultas( ARBOL<int,Persona> *p ){
  Multilista *multiPersona = cargarMultilista(p);
  //Lista<Persona> *eps = NULL;

  Date date; 
  int op;
  string readStr;
  cout<<"¿Qué desea consultar"<<endl;
  cout<<" 1.	Número total de personas que pertenecen a una EPS dada \n" 
          "clasificándolos por rangos de edades acordes con la tabla de edades."<<endl;
  cin>>op;
  cin.ignore();
  switch (op){
    case 1:
      {
        string headers[5] = {"compensar", "sanitas", "nueva", "cafe salud", "famisanar"};     
        for(int i = 0; i<5; i++){
          cout<<"----------------------"<<endl;
          cout<<headers[i]<<endl;
          cout<<"<20:"<<consulta1(multiPersona->listaEdad(0))[i]<<endl;
          cout<<"20-29:"<<consulta1(multiPersona->listaEdad(1))[i]<<endl;
          cout<<"30-39:"<<consulta1(multiPersona->listaEdad(2))[i]<<endl;
          cout<<"40-49:"<<consulta1(multiPersona->listaEdad(3))[i]<<endl;
          cout<<"50-59:"<<consulta1(multiPersona->listaEdad(4))[i]<<endl;
          cout<<"60-69:"<<consulta1(multiPersona->listaEdad(5))[i]<<endl;
          cout<<"70-79:"<<consulta1(multiPersona->listaEdad(6))[i]<<endl;
          cout<<"> 80:"<<consulta1(multiPersona->listaEdad(7))[i]<<endl;
          cout<<"----------------------"<<endl;
          getch();
          system("clear");
        }
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
