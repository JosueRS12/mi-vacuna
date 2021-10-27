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
  cout<<"1)	Número total de personas que pertenecen a una EPS dada \n" 
          "clasificándolos por rangos de edades acordes con la tabla de edades."<<endl;
  cout<<"2) Listado de los nombres y apellidos de aquellos que tienen u\n" "país de nacimiento dado, clasificándolos por ciudad de residencia y EPS a la que pertenecen.MINISTERIO"<<endl;
  cout<<"3) Nombre y apellidos de las personas que viven en una ciudad \n"
    "dada, clasificándolos por EPS y actividad laboral."<<endl;
  cout<<"4)  cantidad de hombres y mujeres vacunados en las \n"
    "diferentes EPS, clasificados por la información por EPS"
    "vacuna que se le aplicó, así como el nombre de la IPS.s "<<endl;
  cout<<"6)  Dado un rango de edad y una actividad laborar mostrar la \n"
    "lista de pacientes en ese rango de edad, clasificados EPS y Ciudad a la que pertenecen."<<endl;
  cin>>op;
  cin.ignore();
  switch (op){
    case 1:
      {
        cout<<"Seleccione la eps: "<<endl;
        cout<<"0) Compensar: "<<endl;
        cout<<"1) Sanitas: "<<endl;
        cout<<"2) Nueva: "<<endl;
        cout<<"3) Cafe Salud: "<<endl;
        cout<<"4) Famisanar: "<<endl;
        cin>>op;
        Lista<Persona> response = multiPersona->listaEps(op);
        cout<<"<20:"<<cruceListas(response , multiPersona->listaEdad(0)).tamLista()<<endl;
        cout<<"20-29:"<<cruceListas(response, multiPersona->listaEdad(1)).tamLista()<<endl;
        cout<<"30-39:"<<cruceListas(response, multiPersona->listaEdad(2)).tamLista()<<endl;
        cout<<"40-49:"<<cruceListas(response, multiPersona->listaEdad(3)).tamLista()<<endl;
        cout<<"50-59:"<<cruceListas(response, multiPersona->listaEdad(4)).tamLista()<<endl;
        cout<<"60-69:"<<cruceListas(response, multiPersona->listaEdad(5)).tamLista()<<endl;
        cout<<"70-79:"<<cruceListas(response, multiPersona->listaEdad(6)).tamLista()<<endl;
        cout<<"> 80:"<<cruceListas(response, multiPersona->listaEdad(7)).tamLista()<<endl;
        cout<<"TOTAL:"<<response.tamLista()<<endl;
        cout<<"----------------------"<<endl;
        getch();
        system("clear");
      }break;
    case 2:
      {
        Lista<Persona> response = Lista<Persona>();
        int op2, op3;
        cout<<"Seleccione el país de nacimiento: "<<endl;
        cout<<"0) Colombia: "<<endl;
        cout<<"1) España: "<<endl;
        cout<<"2) Venezuela: "<<endl;
        cout<<"3) Brasil: "<<endl;
        cin>>op;
        cout<<"----------------------"<<endl;

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(0));//pais ciudad
        cout<<"Bogota: compensar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"Bogota: sanitas"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"Bogota: nueva"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"Bogota: cafe Salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"Bogota: famisanar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(1));//pais ciudad
        cout<<"cali: compensar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"cali: sanitas"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"cali: nueva"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"cali: cafe Salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"cali: famisanar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(2));//pais ciudad
        cout<<"medellin: compensar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"medellin: sanitas"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"medellin: nueva"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"medellin: cafe Salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"medellin: famisanar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(3));//pais ciudad
        cout<<"barranquilla: compensar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"barranquilla: sanitas"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"barranquilla: nueva"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"barranquilla: cafe Salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"barranquilla: famisanar"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaEps(4)));
      }break;
    case 3:
      {
        Lista<Persona> response = Lista<Persona>();
        cout<<"Seleccione la ciudad de Residencia: "<<endl;
        cout<<"0) Bogota: "<<endl;
        cout<<"1) Cali: "<<endl;
        cout<<"2) Medellin: "<<endl;
        cout<<"3) Barranquilla: "<<endl;
        cin>>op;
        response = cruceListas(multiPersona->listaCiudadR(op), multiPersona->listaEps(0));
        cout<<"compensar artes"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(0)));
        cout<<"compensar tecnico"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(1)));
        cout<<"compensar ingenieria"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(2)));
        cout<<"compensar sociales"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(3)));
        cout<<"compensar salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(4)));
        cout<<"compensar otro"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(5)));
        cout<<"----------------------"<<endl;
        response = cruceListas(multiPersona->listaCiudadR(op), multiPersona->listaEps(1));
        cout<<"sanitas artes"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(0)));
        cout<<"sanitas tecnico"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(1)));
        cout<<"sanitas ingenieria"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(2)));
        cout<<"sanitas sociales"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(3)));
        cout<<"sanitas salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(4)));
        cout<<"sanitas otro"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(5)));
        cout<<"-----------------------------------"<<endl;

        response = cruceListas(multiPersona->listaCiudadR(op), multiPersona->listaEps(2));
        cout<<"nueva artes"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(0)));
        cout<<"nueva tecnico"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(1)));
        cout<<"nueva ingenieria"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(2)));
        cout<<"nueva sociales"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(3)));
        cout<<"nueva salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(4)));
        cout<<"nueva otro"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(5)));
        cout<<"----------------------------------"<<endl;

        response = cruceListas(multiPersona->listaCiudadR(op), multiPersona->listaEps(3));
        cout<<"cafe salud artes"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(0)));
        cout<<"cafe salud tecnico"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(1)));
        cout<<"cafe salud ingenieria"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(2)));
        cout<<"cafe salud sociales"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(3)));
        cout<<"cafe salud salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(4)));
        cout<<"cafe salud otro"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(5)));
        cout<<"----------------------------------"<<endl;

        response = cruceListas(multiPersona->listaCiudadR(op), multiPersona->listaEps(4));
        cout<<"famisanar artes"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(0)));
        cout<<"famisanar tecnico"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(1)));
        cout<<"famisanar ingenieria"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(2)));
        cout<<"famisanar sociales"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(3)));
        cout<<"famisanar salud"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(4)));
        cout<<"famisanar otro"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(response, multiPersona->listaActividad(5)));
        cout<<"---------------------------------"<<endl;
      }break;
    case 4:
      {
        Lista<Persona> responseHombre = multiPersona->listaSexo(0);
        Lista<Persona> responseMujer = multiPersona->listaSexo(1);
        Lista<Persona> response = Lista<Persona>(); 

        cout<<"             HOMBRES           "<<endl;
        response = cruceListas(responseHombre, multiPersona->listaEps(0));
        cout<<"Bogota: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"Bogota: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"Bogota: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"Bogota: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"Bogota: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(1));//pais ciudad
        cout<<"cali: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"cali: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"cali: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"cali: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"cali: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(2));//pais ciudad
        cout<<"medellin: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"medellin: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"medellin: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"medellin: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"medellin: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(3));//pais ciudad
        cout<<"barranquilla: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"barranquilla: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"barranquilla: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"barranquilla: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"barranquilla: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));
        cout<<" total: "<<responseHombre.tamLista();
        cout<<"--------------------------------------"<<endl;
        cout<<"            MUJERES           "<<endl;
        response = cruceListas(responseMujer, multiPersona->listaEps(0));
        cout<<"Bogota: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"Bogota: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"Bogota: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"Bogota: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"Bogota: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(1));//pais ciudad
        cout<<"cali: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"cali: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"cali: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"cali: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"cali: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(2));//pais ciudad
        cout<<"medellin: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"medellin: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"medellin: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"medellin: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"medellin: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));

        response = cruceListas(multiPersona->listaPaisN(op), multiPersona->listaCiudadR(3));//pais ciudad
        cout<<"barranquilla: compensar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(0)));
        cout<<"barranquilla: sanitas"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(1)));
        cout<<"barranquilla: nueva"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(2)));
        cout<<"barranquilla: cafe Salud"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(3)));
        cout<<"barranquilla: famisanar"<<"----------------"<<endl;
        mostrarVarios(cruceListas(response, multiPersona->listaEps(4)));
        cout<<" total: "<<responseMujer.tamLista();
        cout<<"--------------------------------------"<<endl;
      }break;
    case 5:
      {

      }break;
    case 6:
      {
        int op2 = 0;
        cout<<"Seleccione el rango de edad: "<<endl;
        cout<<" 0) <20:"<<endl; 
        cout<<" 1)20-29:"<<endl;
        cout<<" 2)30-39:"<<endl;
        cout<<" 3)40-49:"<<endl;
        cout<<" 4)50-59:"<<endl;
        cout<<" 5)60-69:"<<endl;
        cout<<" 6)70-79:"<<endl;
        cout<<" 7)> 80:"<<endl;
        cin>>op;
        cout<<"Seleccione la actividad: "<<endl;
        cout<<"0) Artes"<<endl;
        cout<<"1) tecnico"<<endl;
        cout<<"2) Ingenieria"<<endl;
        cout<<"3) Ciencias Sociales"<<endl;
        cout<<"4) Areas de la Salud"<<endl;
        cout<<"5) otros"<<endl;
        cin>>op2;
        Lista<Persona> responseEdad = cruceListas(multiPersona->listaEdad(op), multiPersona->listaActividad(op2));
        Lista<Persona> responseEps = Lista<Persona>();
        responseEps = cruceListas(responseEdad, multiPersona->listaEps(0));
        cout<<"compensar Bogota"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(0)));
        cout<<"compensar cali"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(1)));
        cout<<"compensar medellin"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(2)));
        cout<<"compensar barranquilla"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(3)));
      
        cout<<"----------------------"<<endl;
        responseEps = cruceListas(responseEdad, multiPersona->listaEps(1));
        cout<<"sanitas Bogota"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(0)));
        cout<<"sanitas cali"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(1)));
        cout<<"sanitas medellin"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(2)));
        cout<<"sanitas barranquilla"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(3)));
        cout<<"-----------------------------------"<<endl;

        responseEps = cruceListas(responseEdad, multiPersona->listaEps(2));
        cout<<"nueva Bogota"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(0)));
        cout<<"nueva cali"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(1)));
        cout<<"nueva medellin"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(2)));
        cout<<"nueva barranquilla"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(3)));
       

        responseEps = cruceListas(responseEdad, multiPersona->listaEps(3));
        cout<<"cafe salud Bogota"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(0)));
        cout<<"cafe salud cali"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(1)));
        cout<<"cafe salud medellin"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(2)));
        cout<<"cafe salud barranquilla"<<"----------------"<<endl;
        
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(5)));
        cout<<"----------------------------------"<<endl;

        responseEps = cruceListas(responseEdad, multiPersona->listaEps(4));
        cout<<"famisanar Bogota"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(0)));
        cout<<"famisanar cali"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(1)));
        cout<<"famisanar medellin"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(2)));
        cout<<"famisanar barranquilla"<<"----------------"<<endl;
        mostrarNombresApellidos(cruceListas(responseEps, multiPersona->listaCiudadR(3)));
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
