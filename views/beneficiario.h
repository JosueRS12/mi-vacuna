#ifndef BENEFICIARIO_H
#define BENEFICIARIO_H
#include <iostream>
#include <cstdlib>
#include <wchar.h>
#include <stdio.h>
#include "../models/Persona.h"
#include "../models/date.h"
#include <string>

using namespace std;


int menuBeneficiario(){
  int op;
  cout<<"¿Qué operación desea realizar?"<<endl;
  cout<<"1) Modificar datos"<<endl;
  cout<<"2) Eliminar usuario"<<endl;
  cout<<"3) Consultar usuario"<<endl;
  cout<<"4) Salir"<<endl;
  cin>> op;
  cin.ignore();
  return op;
}


bool beneficiarioEliminar(Persona *p){
  return true;
}

void beneficiarioModificar(Persona *p){
  Date date; 
  int op, readInt;
  string readStr;
  cout<<"¿Qué desea modificar"<<endl;
  cout<<"1) Nombre"<<endl;
  cout<<"2) Apellido"<<endl;
  cout<<"3) tipo id"<<endl;
  cout<<"4) sexo"<<endl;
  cout<<"5) celular"<<endl;
  cout<<"6) fijo"<<endl;
  cout<<"7) correo"<<endl;
  cout<<"8) ciudad de residencia"<<endl;
  cout<<"9) direccion"<<endl;
  cout<<"10) Actividad laboral"<<endl;
  cout<<"11) Eps"<<endl;
  cout<<"12) salir"<<endl;
  cin>>op;
  cin.ignore();
  switch (op){
    case 1:
      {
        cout<<"Digite el nombre: "<<endl;
        getline(cin, readStr);
        p->setNombre(readStr);
      }break;
    case 2:
      {
        cout<<"Digite el apellido"<<endl;
        getline(cin, readStr);
        p->setApellido(readStr);
      }break;
    case 3:
      {
        cout<<"Digite el tipo de identificación (cc,ce,ti)"<<endl;
        getline(cin, readStr);
        p->setTipoId(readStr);
      }break;
    case 4:
      {
        cout<<"seleccione el sexo (M/f)"<<endl;
        cout<<"1) m. 2) f."<<endl;
        cin>> readInt;
        cin.ignore();
        if(readInt == 1)
          p->setSexo('m');
        else
          p->setSexo('f');
      }break;
    case 5:
      {
        cout<<"Digite el celular"<<endl;
        getline(cin, readStr);
        p->setCelular(readStr);
      }break;
    case 6:
      {
        cout<<"Digite el numero fijo"<<endl;
        getline(cin, readStr);
        p->setFijo(readStr);
      }break;
    case 7:
      {
        cout<<"Digite el correo electrónico"<<endl;
        getline(cin, readStr);
        p->setCorreo(readStr);
      }break;
    case 8:
      {
        cout<<"Digite la ciudad de residencia"<<endl;
        cout<<"1) Bogota"<<endl;
        cout<<"2) Cali"<<endl;
        cout<<"3) Medellin"<<endl;
        cout<<"4) Barranquilla"<<endl;
        cin>>op;
        cin.ignore();
        switch (op){
          case 1:
            {
              p->setCiudadR("bogota");
            }break;
          case 2:
            {
              p->setCiudadR("cali");
            }break;
          case 3:
            {
              p->setCiudadR("medellin");
            }break;
          case 4:
            {
              p->setCiudadR("barranquilla");
            }break;
          default:
            cout<<"vuelva pronto"<<endl;
            break;
        }
      }break;
    case 9:
      {
        cout<<"Digite la dirección"<<endl;
        getline(cin, readStr);
        p->setDireccion(readStr);
      }break;
    case 10:
      {
        cout<<"Selecciona la actividad laboral en la que se desempeña"<<endl;
        cout<<"1) Artes"<<endl;
        cout<<"2) Ingenieria"<<endl;
        cout<<"3) Ciencias Sociales"<<endl;
        cout<<"4) Areas de la Salud"<<endl;
        cout<<"5) otros"<<endl;
        cin>>op;
        switch (op){
          case 1:
            {
              p->setActividad("artes");
            }break;
          case 2:
            {
              p->setActividad("ingenieria");
            }break;
          case 3:
            {
              p->setActividad("ciencias");
            }break;
          case 4:
            {
              p->setActividad("areas");
            }break;
          case 5:
            {
              p->setActividad("otros");
            }break;
          default:
            cout<<"vuelva pronto"<<endl;
            break;
        }
      }break;
    case 11:
      {
        cout<<"Seleccione el nombre de la eps"<<endl;
        cout<<"1) Compensar"<<endl;
        cout<<"2) Sanitas"<<endl;
        cout<<"3) Nueva "<<endl;
        cout<<"4) Cafe Salud"<<endl;
        cout<<"5) Famisanar "<<endl;
        cin>>op;
        switch (op){
          case 1:
            {
              p->setNombreEps("compensar");
            }break;
          case 2:
            {
              p->setNombreEps("sanitas");
            }break;
          case 3:
            {
              p->setNombreEps("nueva");
            }break;
          case 4:
            {
              p->setNombreEps("cafeSalud");
            }break;
          case 5:
            {
              p->setNombreEps("famisanar");
            }break;
          default:
            cout<<"f en el chat"<<endl;
            break;
        }
      }break;
    default:
      cout<<"vuelva pronto"<<endl;
      break;
  }
}
#endif
