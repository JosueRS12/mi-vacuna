#ifndef MULTILISTA_H
#define MULTILISTA_H

//insertarOrdenado
#include <iostream>
#include <cstdlib>
#include "../models/Persona.h"
#include "lista.h"
#include <ctime>

using namespace std;

struct Personita{
  Persona *p;
  Personita *sigSexo, *sigEdad, *sigActividad, *sigPaisN, *sigCiudadR, *sigEps;
};

struct Cabecera{
  Personita *head;
  string tipo;
};

class Multilista{
  Nodo<Personita> *headPersonitas;
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int cYear = 1900+ltm->tm_year; 
  Personita *personita;
  Cabecera *cabeceraSexo, *cabeceraEdad, *cabeceraActividad, *cabeceraPaisN, *cabeceraCiudadR, *cabeceraEps;
  Lista<Personita> listaPersonitas; 
  int tam;

  public:
  Multilista(){
    tam = 0;
    cabeceraSexo = new Cabecera[2]; 
    cabeceraEdad = new Cabecera[8]; 
    cabeceraActividad = new Cabecera[6]; 
    cabeceraPaisN = new Cabecera[4]; 
    cabeceraCiudadR = new Cabecera[4]; 
    cabeceraEps = new Cabecera[5]; 
    cabeceraSexo[0] = {NULL, "m"};
    cabeceraSexo[1] = {NULL, "f"};
    cabeceraEdad[0] = {NULL, "20"};
    cabeceraEdad[1] = {NULL, "20-29"};
    cabeceraEdad[2] = {NULL, "30-39"};
    cabeceraEdad[3] = {NULL, "40-49"};
    cabeceraEdad[4] = {NULL, "50-59"};
    cabeceraEdad[5] = {NULL, "60-69"};
    cabeceraEdad[6] = {NULL, "70-79"};
    cabeceraEdad[7] = {NULL, "80"};
    cabeceraActividad[0] = {NULL, "artes"};
    cabeceraActividad[1] = {NULL, "tecnico"};
    cabeceraActividad[2] = {NULL, "ingenieria"};
    cabeceraActividad[3] = {NULL, "sociales"};
    cabeceraActividad[4] = {NULL, "salud"};
    cabeceraActividad[5] = {NULL, "otro"};
    cabeceraPaisN[0] = {NULL, "colombia"};
    cabeceraPaisN[1] = {NULL, "francia"};
    cabeceraPaisN[2] = {NULL, "venezuela"};
    cabeceraPaisN[3] = {NULL, "brasil"};
    cabeceraCiudadR[0] = {NULL, "bogota"};
    cabeceraCiudadR[1] = {NULL, "cali"};
    cabeceraCiudadR[2] = {NULL, "medellin"};
    cabeceraCiudadR[3] = {NULL, "barranquilla"};
    cabeceraEps[0] = {NULL, "compensar"};
    cabeceraEps[1] = {NULL, "sanitas"};
    cabeceraEps[2] = {NULL, "nueva"};
    cabeceraEps[3] = {NULL, "cafeSalud"};
    cabeceraEps[4] = {NULL, "famisanar"};
  } 
  void setCabeceras();
  void insertarPersonita(Persona delSenior);
  void ordenarSexo(Personita delSenior);
  void ordenarEdad(Personita delSenior);
  void ordenarActividad(Personita delSenior);
  void ordenarPaisN(Personita delSenior);
  void ordenarCiudadR(Personita delSenior);
  void ordenarEps(Personita delSenior);
  bool eliminar(Persona);
  Lista<Persona> listaSexo(char);
  Lista<Persona> listaEdad(int);
  Lista<Persona> listaActividad(int);
  Lista<Persona> listaPaisN(int);
  Lista<Persona> listaCiudadR(int);
  Lista<Persona> listaEps(int);
  bool eliminarPersonitaLista (Persona);
  Personita existeActual(Persona);
  bool vacio();
  bool lleno();
};

void Multilista :: insertarPersonita(Persona persona){
  Personita *delSenior = new Personita;
  delSenior->p = &persona; //
  cout<<"del senior"<<&delSenior<<endl;
  cout<<"direccion persona"<<&delSenior->p<<endl;
  ordenarSexo(*delSenior);
  ordenarEdad(*delSenior);
  ordenarActividad(*delSenior);
  ordenarPaisN(*delSenior);
  ordenarCiudadR(*delSenior);
  ordenarEps(*delSenior);
  cout<<"ordenar eps"<<endl;

  listaPersonitas.insertarInicio(*delSenior);
  //cout<<"cabecera"<<cabeceraSexo[0].head->p->getNombre()<<endl;
}

void Multilista :: ordenarSexo(Personita delSenior){
  if(delSenior.p->getSexo() == 'm'){
    if(cabeceraSexo[0].head == NULL){
      cabeceraSexo[0].head = &delSenior;
      //cout<<"cabecera"<<cabeceraSexo[0].head->p->getNombre()<<endl;
    }
    else{
      Personita aux; //funciona
      aux = *cabeceraSexo[0].head;  
      cabeceraSexo[0].head = &delSenior;
      delSenior.sigSexo = &aux; 
      //cout<<"cabecera"<<cabeceraSexo[0].head->p->getNombre()<<endl;
      //cout<<"sig cabecera"<<cabeceraSexo[0].head->sigSexo->p->getNombre()<<endl;
    }
  }


  if(delSenior.p->getSexo() == 'f'){
    if(cabeceraSexo[1].head == NULL)
      cabeceraSexo[1].head = &delSenior;
    else{
      Personita *aux = NULL; //funciona
      aux = cabeceraSexo[1].head; 
      cabeceraSexo[1].head = &delSenior;
      delSenior.sigSexo = aux; 
    }
  }
}

void Multilista :: ordenarEdad(Personita delSenior){
  int edad = delSenior.p->getFechaN().getYear() - cYear;
  Personita *aux = new Personita(); //funciona 
  if(edad < 20){
    if(cabeceraEdad[0].head == NULL)
      cabeceraEdad[0].head = &delSenior;
    else{
      aux = cabeceraEdad[0].head; 
      cabeceraEdad[0].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }

  if(edad >= 20 && edad <= 29){
    if(cabeceraEdad[1].head == NULL)
      cabeceraEdad[1].head = &delSenior;
    else{
      aux = cabeceraEdad[1].head; 
      cabeceraEdad[1].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }

  if(edad >= 30 && edad <= 39){
    if(cabeceraEdad[2].head == NULL)
      cabeceraEdad[2].head = &delSenior;
    else{
      aux = cabeceraEdad[2].head; 
      cabeceraEdad[2].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }

  if(edad >= 40 && edad <= 49){
    if(cabeceraEdad[3].head == NULL)
      cabeceraEdad[3].head = &delSenior;
    else{
      aux = cabeceraEdad[3].head; 
      cabeceraEdad[3].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }

  if(edad >= 50 && edad <= 59){
    if(cabeceraEdad[4].head == NULL)
      cabeceraEdad[4].head = &delSenior;
    else{
      aux = cabeceraEdad[4].head; 
      cabeceraEdad[4].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }

  if(edad >= 60 && edad <= 69){
    if(cabeceraEdad[5].head == NULL)
      cabeceraEdad[5].head = &delSenior;
    else{
      aux = cabeceraEdad[5].head; 
      cabeceraEdad[5].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }

  if(edad >= 70 && edad <= 79){
    if(cabeceraEdad[6].head == NULL)
      cabeceraEdad[6].head = &delSenior;
    else{
      aux = cabeceraEdad[6].head; 
      cabeceraEdad[6].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }

  if(edad >= 80){
    if(cabeceraEdad[7].head == NULL)
      cabeceraEdad[7].head = &delSenior;
    else{
      aux = cabeceraEdad[7].head; 
      cabeceraEdad[7].head = &delSenior;
      delSenior.sigEdad = aux; 
    }
  }
}

void Multilista :: ordenarActividad(Personita delSenior){
  Personita *aux = new Personita(); //funciona
  if(delSenior.p->getActividad() == "artes"){
    if(cabeceraActividad[0].head == NULL)
      cabeceraActividad[0].head = &delSenior;
    else{
      aux = cabeceraActividad[0].head; 
      cabeceraActividad[0].head = &delSenior;
      delSenior.sigActividad = aux; 
    }
  }

  if(delSenior.p->getActividad() == "tecnico"){
    if(cabeceraActividad[1].head == NULL)
      cabeceraActividad[1].head = &delSenior;
    else{
      aux = cabeceraActividad[1].head; 
      cabeceraActividad[1].head = &delSenior;
      delSenior.sigActividad = aux; 
    }
  }

  if(delSenior.p->getActividad() == "ingenieria"){
    if(cabeceraActividad[2].head == NULL)
      cabeceraActividad[2].head = &delSenior;
    else{
      aux = cabeceraActividad[2].head; 
      cabeceraActividad[2].head = &delSenior;
      delSenior.sigActividad = aux; 
    }
  }

  if(delSenior.p->getActividad() == "sociales"){
    if(cabeceraActividad[3].head == NULL)
      cabeceraActividad[3].head = &delSenior;
    else{
      aux = cabeceraActividad[3].head; 
      cabeceraActividad[3].head = &delSenior;
      delSenior.sigActividad = aux; 
    }
  }

  if(delSenior.p->getActividad() == "salud"){
    if(cabeceraActividad[4].head == NULL)
      cabeceraActividad[4].head = &delSenior;
    else{
      aux = cabeceraActividad[4].head; 
      cabeceraActividad[4].head = &delSenior;
      delSenior.sigActividad = aux; 
    }
  }

  if(delSenior.p->getActividad() == "otro"){
    if(cabeceraActividad[5].head == NULL)
      cabeceraActividad[5].head = &delSenior;
    else{
      aux = cabeceraActividad[5].head; 
      cabeceraActividad[5].head = &delSenior;
      delSenior.sigActividad = aux; 
    }
  }
}

void Multilista :: ordenarPaisN(Personita delSenior){
  Personita *aux = new Personita(); //funciona
  if(delSenior.p->getPaisN() == "colombia"){
    if(cabeceraPaisN[0].head == NULL)
      cabeceraPaisN[0].head = &delSenior;
    else{
      aux = cabeceraPaisN[0].head; 
      cabeceraPaisN[0].head = &delSenior;
      delSenior.sigPaisN = aux; 
    }
  }

  if(delSenior.p->getPaisN() == "francia"){
    if(cabeceraPaisN[1].head == NULL)
      cabeceraPaisN[1].head = &delSenior;
    else{
      aux = cabeceraPaisN[1].head; 
      cabeceraPaisN[1].head = &delSenior;
      delSenior.sigPaisN = aux; 
    }
  }

  if(delSenior.p->getPaisN() == "venezuela"){
    if(cabeceraPaisN[2].head == NULL)
      cabeceraPaisN[2].head = &delSenior;
    else{
      aux = cabeceraPaisN[2].head; 
      cabeceraPaisN[2].head = &delSenior;
      delSenior.sigPaisN = aux; 
    }
  }

  if(delSenior.p->getPaisN() == "brasil"){
    if(cabeceraPaisN[3].head == NULL)
      cabeceraPaisN[3].head = &delSenior;
    else{
      aux = cabeceraPaisN[3].head; 
      cabeceraPaisN[3].head = &delSenior;
      delSenior.sigPaisN = aux; 
    }
  }
}

void Multilista :: ordenarCiudadR(Personita delSenior){
  Personita *aux = new Personita(); //funciona
  if(delSenior.p->getCiudadR() == "bogota"){
    if(cabeceraCiudadR[0].head == NULL)
      cabeceraCiudadR[0].head = &delSenior;
    else{
      aux = cabeceraCiudadR[0].head; 
      cabeceraCiudadR[0].head = &delSenior;
      delSenior.sigCiudadR = aux; 
    }
  }

  if(delSenior.p->getCiudadR() == "cali"){
    if(cabeceraCiudadR[1].head == NULL)
      cabeceraCiudadR[1].head = &delSenior;
    else{
      aux = cabeceraCiudadR[1].head; 
      cabeceraCiudadR[1].head = &delSenior;
      delSenior.sigCiudadR = aux; 
    }
  }

  if(delSenior.p->getCiudadR() == "medellin"){
    if(cabeceraCiudadR[2].head == NULL)
      cabeceraCiudadR[2].head = &delSenior;
    else{
      aux = cabeceraCiudadR[2].head; 
      cabeceraCiudadR[2].head = &delSenior;
      delSenior.sigCiudadR = aux; 
    }
  }

  if(delSenior.p->getCiudadR() == "barranquilla"){
    if(cabeceraCiudadR[3].head == NULL)
      cabeceraCiudadR[3].head = &delSenior;
    else{
      aux = cabeceraCiudadR[3].head; 
      cabeceraCiudadR[3].head = &delSenior;
      delSenior.sigCiudadR = aux; 
    }
  }
}

void Multilista ::  ordenarEps(Personita delSenior){
  Personita *aux = new Personita(); //funciona
  if(delSenior.p->getNombreEps() == "compensar"){
    if(cabeceraEps[0].head == NULL)
      cabeceraEps[0].head = &delSenior;
    else{
      aux = cabeceraEps[0].head; 
      cabeceraEps[0].head = &delSenior;
      delSenior.sigEps = aux; 
    }
  }

  if(delSenior.p->getNombreEps() == "sanitas"){
    if(cabeceraEps[1].head == NULL)
      cabeceraEps[1].head = &delSenior;
    else{
      aux = cabeceraEps[1].head; 
      cabeceraEps[1].head = &delSenior;
      delSenior.sigEps = aux; 
    }
  }

  if(delSenior.p->getNombreEps() == "nueva"){
    if(cabeceraEps[2].head == NULL)
      cabeceraEps[2].head = &delSenior;
    else{
      aux = cabeceraEps[2].head; 
      cabeceraEps[2].head = &delSenior;
      delSenior.sigEps = aux; 
    }
  }

  if(delSenior.p->getNombreEps() == "cafeSalud"){
    if(cabeceraEps[3].head == NULL)
      cabeceraEps[3].head = &delSenior;
    else{
      aux = cabeceraEps[3].head; 
      cabeceraEps[3].head = &delSenior;
      delSenior.sigEps = aux; 
    }
  }

  if(delSenior.p->getNombreEps() == "famisanar"){
    if(cabeceraEps[4].head == NULL)
      cabeceraEps[4].head = &delSenior;
    else{
      aux = cabeceraEps[4].head; 
      cabeceraEps[4].head = &delSenior;
      delSenior.sigEps = aux; 
    }
  }
}

Lista<Persona> Multilista::listaSexo(char sexo){
  cout<<"ant declarar"<<endl;
  Lista<Persona> listaPersona = Lista<Persona>();
  cout<<"des declarar"<<endl;
  if(sexo == 'm'){
  cout<<"1"<<endl;
    Personita *aux = cabeceraSexo[0].head;
  cout<<"cabecera"<<cabeceraSexo[0].head->p->getSexo()<<endl;
    while(aux != NULL){
      cout<<"3"<<endl;
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigSexo;
    }
    
  }

  if(sexo == 'f'){
    cout<<"4"<<endl;
    Personita *aux = cabeceraSexo[1].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigSexo;
    }
  }
  return listaPersona;
}

Lista<Persona> Multilista::listaEdad(int num){
  Lista<Persona> listaPersona;
  if(num == 0){
    Personita *aux = cabeceraEdad[0].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }

  if(num == 1){
    Personita *aux = cabeceraEdad[1].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }

  if(num == 2){
    Personita *aux = cabeceraEdad[2].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }

  if(num == 3){
    Personita *aux = cabeceraEdad[3].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }

  if(num == 4){
    Personita *aux = cabeceraEdad[4].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }

  if(num == 5){
    Personita *aux = cabeceraEdad[5].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }

  if(num == 6){
    Personita *aux = cabeceraEdad[6].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }

  if(num == 7){
    Personita *aux = cabeceraEdad[7].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEdad;
    }
  }
  return listaPersona;
}

Lista<Persona> Multilista::listaActividad(int num){
  Lista<Persona> listaPersona;
  if(num == 0){
    Personita *aux = cabeceraActividad[0].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigActividad;
    }
  }

  if(num == 1){
    Personita *aux = cabeceraActividad[1].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigActividad;
    }
  }

  if(num == 2){
    Personita *aux = cabeceraActividad[2].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigActividad;
    }
  }

  if(num == 3){
    Personita *aux = cabeceraActividad[3].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigActividad;
    }
  }

  if(num == 4){
    Personita *aux = cabeceraActividad[4].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigActividad;
    }
  }

  if(num == 5){
    Personita *aux = cabeceraActividad[5].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigActividad;
    }
  }
  return listaPersona;
}
  
Lista<Persona> Multilista::listaPaisN(int num){
  Lista<Persona> listaPersona;
  if(num == 0){
    Personita *aux = cabeceraPaisN[0].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigPaisN;
    }
  }

  if(num == 1){
    Personita *aux = cabeceraPaisN[1].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigPaisN;
    }
  }

  if(num == 2){
    Personita *aux = cabeceraPaisN[2].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigPaisN;
    }
  }

  if(num == 3){
    Personita *aux = cabeceraPaisN[3].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigPaisN;
    }
  }
  return listaPersona;
}

Lista<Persona> Multilista::listaCiudadR(int num){
  Lista<Persona> listaPersona;
  if(num == 0){
    Personita *aux = cabeceraCiudadR[0].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigCiudadR;
    }
  }

  if(num == 1){
    Personita *aux = cabeceraCiudadR[1].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigCiudadR;
    }
  }

  if(num == 2){
    Personita *aux = cabeceraCiudadR[2].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigCiudadR;
    }
  }

  if(num == 3){
    Personita *aux = cabeceraCiudadR[3].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigCiudadR;
    }
  }
  return listaPersona;
}


Lista<Persona> Multilista::listaEps(int num){
  Lista<Persona> listaPersona;
  if(num == 0){
    Personita *aux = cabeceraEps[0].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEps;
    }
  }

  if(num == 1){
    Personita *aux = cabeceraEps[1].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEps;
    }
  }

  if(num == 2){
    Personita *aux = cabeceraEps[2].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEps;
    }
  }

  if(num == 3){
    Personita *aux = cabeceraEps[3].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEps;
    }
  }

  if(num == 4){
    Personita *aux = cabeceraEps[4].head;
    while(aux != NULL){
      listaPersona.insertarInicio(*aux->p);
      aux = aux->sigEps;
    }
  }
  return listaPersona;
}
#endif
