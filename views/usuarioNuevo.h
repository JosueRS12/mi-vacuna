#ifndef USUARIONUEVO_H
#define USUARIONUEVO_H
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <wchar.h>
#include "../models/Persona.h"
#include "../models/date.h"
#include <string>

using namespace std;

Persona usuarioNuevo(){
  Persona p;
  Date date; 
  int op, readInt;
  string readStr;

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
  cout<<"1) Colombia"<<endl;
  cout<<"2) España"<<endl;
  cout<<"3) Venezuela"<<endl;
  cout<<"4) Brasil"<<endl;
  cin>>op;
  cin.ignore();
  switch (op){
    case 1:
      {
        p.setPaisN("colombia");
      }break;
    case 2:
      {
        p.setPaisN("españa");
      }break;
    case 3:
      {
        p.setPaisN("Venezuela");
      }break;
    case 4:
      {
        p.setPaisN("Brasil");
      }break;
    default:
      cout<<"vuelva pronto"<<endl;
      break;
  }
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
        p.setCiudadR("bogota");
      }break;
    case 2:
      {
        p.setCiudadR("cali");
      }break;
    case 3:
      {
        p.setCiudadR("medellin");
      }break;
    case 4:
      {
        p.setCiudadR("barranquilla");
      }break;
    default:
      cout<<"vuelva pronto"<<endl;
      break;
  }
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
  cin>>op;
  switch (op){
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
  cin>>op;
  switch (op){
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
    default:
      break;
  }
  if(p.getTipoVacuna() != " "){
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
    if(dosis == 1){
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
  return p;
};
#endif
