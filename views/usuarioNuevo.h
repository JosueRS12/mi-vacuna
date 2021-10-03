#ifndef USUARIONUEVO_H
#define USUARIONUEVO_H
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "../models/Persona.h"
#include "../models/date.h"
#include <string>

using namespace std;

void usuarioNuevo(){
  Persona p;
  Date date; 
  int op,op2,op3, readInt;
  string readStr;
  char readS[50];
  char readChar;

  cout<<"Digite el nombre: "<<endl;
  getline(cin, readStr);
  p.setNombre(readStr);
  cout<<"Digite el apellido"<<endl;
  getline(cin, readStr);
  p.setApellido(readStr);
  cout<<"Digite el tipo de identificación (cc,ce,ti)"<<endl;
  getline(cin, readStr);
  p.setTipoId(readStr);
  cout<<"Digite el numero de identificación"<<endl;
  cin>> readInt;
  cin.ignore();
  p.setNumeroId(readInt);
  cout<<"seleccione el sexo (M/f)"<<endl;
  cout<<"1) m. 2) f."<<endl;
  cin>> readInt;
  cin.ignore();
  if(readInt == 1)
    p.setSexo('m');
  else
    p.setSexo('f');
  cout<<"Digite el celular"<<endl;
  getline(cin, readStr);
  p.setCelular(readStr);
  cout<<"Digite el numero fijo"<<endl;
  getline(cin, readStr);
  p.setFijo(readStr);
  cout<<"Digite el correo electrónico"<<endl;
  getline(cin, readStr);
  p.setCorreo(readStr);
  cout<<"Digite la fecha de nacimiento"<<endl;
  cout<<"dia"<<endl;
  cin>>readInt;
  date.setDay(readInt);
  cout<<"Mes"<<endl;
  cin>>readInt;
  date.setMonth(readInt);
  cout<<"año"<<endl;
  cin>>readInt;
  date.setYear(readInt);
  cin.ignore();
  p.setFechaN(date);
  cout<<"Digite la ciudad de nacimiento"<<endl;
  getline(cin, readStr);
  p.setCiudadN(readStr);
  cout<<"Digite el país de nacimiento"<<endl;
  getline(cin, readStr);
  p.setPaisN(readStr);
  cout<<"Digite la ciudad de residencia"<<endl;
  getline(cin, readStr);
  p.setCiudadR(readStr);
  cout<<"Digite la dirección"<<endl;
  getline(cin, readStr);
  p.setDireccion(readStr);
  cout<<"Digite el barrio"<<endl;
  getline(cin, readStr);
  p.setBarrio(readStr);
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
        p.setActividad("artes");
      }break;
    case 2:
      {
        p.setActividad("ingenieria");
      }break;
    case 3:
      {
        p.setActividad("ciencias");
      }break;
    case 4:
      {
        p.setActividad("areas");
      }break;
    case 5:
      {
        p.setActividad("otros");
      }break;
    default:
      cout<<"vuelva pronto"<<endl;
      break;
  }
  cout<<"Seleccione el nombre de la eps"<<endl;
  cout<<"1) Compensar"<<endl;
  cout<<"2) Sanitas"<<endl;
  cout<<"3) Nueva "<<endl;
  cout<<"4) Cafe Salud"<<endl;
  cout<<"5) Famisanar "<<endl;
  cin>>op2;
  switch (op2){
    case 1:
      {
        p.setNombreEps("compensar");
      }break;
    case 2:
      {
        p.setNombreEps("sanitas");
      }break;
    case 3:
      {
        p.setNombreEps("nueva");
      }break;
    case 4:
      {
        p.setNombreEps("cafeSalud");
      }break;
    case 5:
      {
        p.setNombreEps("famisanar");
      }break;
    default:
      cout<<"f en el chat"<<endl;
      break;
  }
  cout<<"Seleccione el tipo vacuna que le fue aplicada"<<endl;
  cout<<"1) Pfizer "<<endl;
  cout<<"2) Aztrazeneca"<<endl;
  cout<<"3) Johnson"<<endl;
  cout<<"4) Moderna"<<endl;
  cout<<"5) Sputnik "<<endl;
  cout<<"6) Sinovac "<<endl;
  cout<<"7) sin vacunar"<<endl;
  cin>>op3;
  switch (op3){
    case 1:
      {
        p.setTipoVacuna("pfizer");
      }break;
    case 2:
      {
        p.setTipoVacuna("astrazeneca");
      }break;
    case 3:
      {
        p.setTipoVacuna("johnson");
      }break;
    case 4:
      {
        p.setTipoVacuna("moderna");
      }break;
    case 5:
      {
        p.setTipoVacuna("sputnik");
      }break;
    case 6:
      {
        p.setTipoVacuna("sinovac");
      }break;
    case 7:
      {
        p.setTipoVacuna("ninguno");
      }break;
    default:
      break;
  }
  if(p.getTipoVacuna() != "ninguno"){
    cout<<"Digite la fecha de primera dosis"<<endl; // opcinal
    cout<<"dia"<<endl;
    cin>>readInt;
    date.setDay(readInt);
    cout<<"Mes"<<endl;
    cin>>readInt;
    date.setMonth(readInt);
    cout<<"año"<<endl;
    cin>>readInt;
    date.setYear(readInt);
    p.setFechaPrimeraD(date);
    cin.ignore();
    int dosis;
    cout<<"¿Ya se aplicó la segunda dósis"<<endl;
    cout<<"1) si. 2) no"<<endl;
    cin>>dosis;
    if(dosis){
      if(p.getTipoVacuna() != "johnson"){
        cout<<"Digite la fecha de segunda dosis"<<endl; //opcional
        cout<<"dia"<<endl;
        cin>>readInt;
        date.setDay(readInt);
        cout<<"Mes"<<endl;
        cin>>readInt;
        date.setMonth(readInt);
        cout<<"año"<<endl;
        cin>>readInt;
        date.setYear(readInt);
        p.setFechaSegundaD(date);
        cin.ignore();
      }
    }
    if(p.getTipoVacuna() == "johnson"){
      date.setDay(999);
      date.setMonth(999);
      date.setYear(999);
      p.setFechaSegundaD(date);
    }
  }
};
#endif
