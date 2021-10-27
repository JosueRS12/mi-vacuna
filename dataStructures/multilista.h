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
  Persona p;
  int sigSexo, sigEdad, sigActividad, sigPaisN, sigCiudadR, sigEps;
};

struct Cabecera{
  int head;
  string tipo;
};

class Multilista{
  time_t now;
  tm *ltm;
  int cYear; 
  Personita *personita;
  Cabecera *cabeceraSexo, *cabeceraEdad, *cabeceraActividad, *cabeceraPaisN, *cabeceraCiudadR, *cabeceraEps;
  Personita *listaPersonitas; 
  int tam;
  int posLibre;

  public:
  Multilista(int tam){
    posLibre = 0;
    listaPersonitas = new Personita[tam];
    now = time(0);
    ltm = localtime(&now);
    cYear = 1900+ltm->tm_year; 
    tam = 0;
    cabeceraSexo = new Cabecera[2]; 
    cabeceraEdad = new Cabecera[8]; 
    cabeceraActividad = new Cabecera[6]; 
    cabeceraPaisN = new Cabecera[4]; 
    cabeceraCiudadR = new Cabecera[4]; 
    cabeceraEps = new Cabecera[5]; 
    cabeceraSexo[0] = {-1, "m"};
    cabeceraSexo[1] = {-1, "f"};
    cabeceraEdad[0] = {-1, "20"};
    cabeceraEdad[1] = { -1, "20-29"};
    cabeceraEdad[2] = {-1, "30-39"};
    cabeceraEdad[3] = {-1, "40-49"};
    cabeceraEdad[4] = {-1, "50-59"};
    cabeceraEdad[5] = {-1, "60-69"};
    cabeceraEdad[6] = {-1, "70-79"};
    cabeceraEdad[7] = {-1, "80"};
    cabeceraActividad[0] = {-1, "artes"};
    cabeceraActividad[1] = {-1, "tecnico"};
    cabeceraActividad[2] = {-1, "ingenieria"};
    cabeceraActividad[3] = {-1, "sociales"};
    cabeceraActividad[4] = {-1, "salud"};
    cabeceraActividad[5] = {-1, "otro"};
    cabeceraPaisN[0] = {-1, "colombia"};
    cabeceraPaisN[1] = {-1, "españa"};
    cabeceraPaisN[2] = {-1, "venezuela"};
    cabeceraPaisN[3] = {-1, "brasil"};
    cabeceraCiudadR[0] = {-1, "bogota"};
    cabeceraCiudadR[1] = {-1, "cali"};
    cabeceraCiudadR[2] = {-1, "medellin"};
    cabeceraCiudadR[3] = {-1, "barranquilla"};
    cabeceraEps[0] = {-1, "compensar"};
    cabeceraEps[1] = {-1, "sanitas"};
    cabeceraEps[2] = {-1, "nueva"};
    cabeceraEps[3] = {-1, "cafeSalud"};
    cabeceraEps[4] = {-1, "famisanar"};
  } 

  void insertarPersonita(Persona delSenior);
  void ordenarSexo();
  void ordenarEdad();
  void ordenarActividad();
  void ordenarPaisN();
  void ordenarCiudadR();
  void ordenarEps();
  Lista<Persona> listaSexo(char);
  Lista<Persona> listaEdad(int);
  Lista<Persona> listaActividad(int);
  Lista<Persona> listaPaisN(int);
  Lista<Persona> listaCiudadR(int);
  Lista<Persona> listaEps(int);
  void imprimirArray();
};

void Multilista :: imprimirArray(){
  for(int i = 0; i<posLibre; i++){
    cout<<listaPersonitas[i].p.getNombre()<<"  "<<listaPersonitas[i].sigEdad<<endl;
    //cout<<listaPersonitas[i].p.getNombre()<<endl;
  }
}

void Multilista :: insertarPersonita(Persona persona){
  Personita *delSenior = new Personita();
  delSenior->p= persona; //nice
  listaPersonitas[posLibre] = *delSenior;
  ordenarSexo();
  ordenarEdad();
  ordenarActividad();
  ordenarPaisN();
  ordenarCiudadR();
  ordenarEps();
  posLibre++;
}

void Multilista :: ordenarSexo(){
  if(listaPersonitas[posLibre].p.getSexo() == 'm'){
    if(cabeceraSexo[0].head == -1){
      cabeceraSexo[0].head = posLibre;
      listaPersonitas[posLibre].sigSexo = -1;
    }
    else{
      int aux = cabeceraSexo[0].head;  
      cabeceraSexo[0].head = posLibre;
      listaPersonitas[posLibre].sigSexo = aux;
    }
  }
  if(listaPersonitas[posLibre].p.getSexo() == 'f'){
    if(cabeceraSexo[1].head == -1){
      cabeceraSexo[1].head = posLibre;
      listaPersonitas[posLibre].sigSexo = -1;
    }
    else{
      int aux = cabeceraSexo[1].head;  
      cabeceraSexo[1].head = posLibre;
      listaPersonitas[posLibre].sigSexo = aux;
    }
  }
}

void Multilista :: ordenarEdad(){
  int edad = cYear - listaPersonitas[posLibre].p.getFechaN().getYear() ;
  if(edad < 20){
      if(cabeceraEdad[0].head == -1){
        cabeceraEdad[0].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[0].head;  
        cabeceraEdad[0].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }

    if(edad >= 20 && edad <= 29){
      if(cabeceraEdad[1].head == -1){
        cabeceraEdad[1].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[1].head;  
        cabeceraEdad[1].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }

    if(edad >= 30 && edad <= 39){
      if(cabeceraEdad[2].head == -1){
        cabeceraEdad[2].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[2].head;  
        cabeceraEdad[2].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }

    if(edad >= 40 && edad <= 49){
      if(cabeceraEdad[3].head == -1){
        cabeceraEdad[3].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[3].head;  
        cabeceraEdad[3].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }

    if(edad >= 50 && edad <= 59){
      if(cabeceraEdad[4].head == -1){
        cabeceraEdad[4].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[4].head;  
        cabeceraEdad[4].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }

    if(edad >= 60 && edad <= 69){
      if(cabeceraEdad[5].head == -1){
        cabeceraEdad[5].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[5].head;  
        cabeceraEdad[5].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }

    if(edad >= 70 && edad <= 79){
      if(cabeceraEdad[6].head == -1){
        cabeceraEdad[6].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[6].head;  
        cabeceraEdad[6].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }

    if(edad >= 80){
      if(cabeceraEdad[7].head == -1){
        cabeceraEdad[7].head = posLibre;
        listaPersonitas[posLibre].sigEdad = -1;
      }
      else{
        int aux = cabeceraEdad[7].head;  
        cabeceraEdad[7].head = posLibre;
        listaPersonitas[posLibre].sigEdad = aux;
      }
    }
}

void Multilista :: ordenarActividad(){
  if(listaPersonitas[posLibre].p.getActividad() == "artes"){
      if(cabeceraActividad[0].head == -1){
        cabeceraActividad[0].head = posLibre;
        listaPersonitas[posLibre].sigActividad = -1;
      }
      else{
        int aux = cabeceraActividad[0].head;  
        cabeceraActividad[0].head = posLibre;
        listaPersonitas[posLibre].sigActividad = aux;
      }
  }
  if(listaPersonitas[posLibre].p.getActividad() == "tecnico"){
      if(cabeceraActividad[1].head == -1){
        cabeceraActividad[1].head = posLibre;
        listaPersonitas[posLibre].sigActividad = -1;
      }
      else{
        int aux = cabeceraActividad[1].head;  
        cabeceraActividad[1].head = posLibre;
        listaPersonitas[posLibre].sigActividad = aux;
      }
  }

  if(listaPersonitas[posLibre].p.getActividad() == "ingenieria"){
      if(cabeceraActividad[2].head == -1){
        cabeceraActividad[2].head = posLibre;
        listaPersonitas[posLibre].sigActividad = -1;
      }
      else{
        int aux = cabeceraActividad[2].head;  
        cabeceraActividad[2].head = posLibre;
        listaPersonitas[posLibre].sigActividad = aux;
      }
  }
  if(listaPersonitas[posLibre].p.getActividad() == "sociales"){
      if(cabeceraActividad[3].head == -1){
        cabeceraActividad[3].head = posLibre;
        listaPersonitas[posLibre].sigActividad = -1;
      }
      else{
        int aux = cabeceraActividad[3].head;  
        cabeceraActividad[3].head = posLibre;
        listaPersonitas[posLibre].sigActividad = aux;
      }
  }

  if(listaPersonitas[posLibre].p.getActividad() == "salud"){
      if(cabeceraActividad[4].head == -1){
        cabeceraActividad[4].head = posLibre;
        listaPersonitas[posLibre].sigActividad = -1;
      }
      else{
        int aux = cabeceraActividad[4].head;  
        cabeceraActividad[4].head = posLibre;
        listaPersonitas[posLibre].sigActividad = aux;
      }
  }

  if(listaPersonitas[posLibre].p.getActividad() == "otro"){
      if(cabeceraActividad[5].head == -1){
        cabeceraActividad[5].head = posLibre;
        listaPersonitas[posLibre].sigActividad = -1;
      }
      else{
        int aux = cabeceraActividad[5].head;  
        cabeceraActividad[5].head = posLibre;
        listaPersonitas[posLibre].sigActividad = aux;
      }
  }
}

void Multilista :: ordenarPaisN(){
  if(listaPersonitas[posLibre].p.getPaisN() == "colombia"){
    if(cabeceraPaisN[0].head == -1){
      cabeceraPaisN[0].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = -1;
    }
    else{
      int aux = cabeceraPaisN[0].head;  
      cabeceraPaisN[0].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = aux;
    }
  }

  if(listaPersonitas[posLibre].p.getPaisN() == "españa"){
    if(cabeceraPaisN[1].head == -1){
      cabeceraPaisN[1].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = -1;
    }
    else{
      int aux = cabeceraPaisN[1].head;  
      cabeceraPaisN[1].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = aux;
    }
  }

  if(listaPersonitas[posLibre].p.getPaisN() == "venezuela"){
    if(cabeceraPaisN[2].head == -1){
      cabeceraPaisN[2].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = -1;
    }
    else{
      int aux = cabeceraPaisN[2].head;  
      cabeceraPaisN[2].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = aux;
    }
  }

  if(listaPersonitas[posLibre].p.getPaisN() == "brasil"){
    if(cabeceraPaisN[3].head == -1){
      cabeceraPaisN[3].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = -1;
    }
    else{
      int aux = cabeceraPaisN[3].head;  
      cabeceraPaisN[3].head = posLibre;
      listaPersonitas[posLibre].sigPaisN = aux;
    }
  }
}

void Multilista :: ordenarCiudadR(){
 if(listaPersonitas[posLibre].p.getCiudadR() == "bogota"){
    if(cabeceraCiudadR[0].head == -1){
      cabeceraCiudadR[0].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = -1;
    }
    else{
      int aux = cabeceraCiudadR[0].head;  
      cabeceraCiudadR[0].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = aux;
    }
  }

  if(listaPersonitas[posLibre].p.getCiudadR() == "cali"){
    if(cabeceraCiudadR[1].head == -1){
      cabeceraCiudadR[1].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = -1;
    }
    else{
      int aux = cabeceraCiudadR[1].head;  
      cabeceraCiudadR[1].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = aux;
    }
  }
  if(listaPersonitas[posLibre].p.getCiudadR() == "medellin"){
    if(cabeceraCiudadR[2].head == -1){
      cabeceraCiudadR[2].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = -1;
    }
    else{
      int aux = cabeceraCiudadR[2].head;  
      cabeceraCiudadR[2].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = aux;
    }
  }
  if(listaPersonitas[posLibre].p.getCiudadR() == "barranquilla"){
    if(cabeceraCiudadR[3].head == -1){
      cabeceraCiudadR[3].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = -1;
    }
    else{
      int aux = cabeceraCiudadR[3].head;  
      cabeceraCiudadR[3].head = posLibre;
      listaPersonitas[posLibre].sigCiudadR = aux;
    }
  }
}

void Multilista ::  ordenarEps(){
if(listaPersonitas[posLibre].p.getNombreEps() == "compensar"){
    if(cabeceraEps[0].head == -1){
      cabeceraEps[0].head = posLibre;
      listaPersonitas[posLibre].sigEps = -1;
    }
    else{
      int aux = cabeceraEps[0].head;  
      cabeceraEps[0].head = posLibre;
      listaPersonitas[posLibre].sigEps = aux;
    }
  }

  if(listaPersonitas[posLibre].p.getNombreEps() == "sanitas"){
    if(cabeceraEps[1].head == -1){
      cabeceraEps[1].head = posLibre;
      listaPersonitas[posLibre].sigEps = -1;
    }
    else{
      int aux = cabeceraEps[1].head;  
      cabeceraEps[1].head = posLibre;
      listaPersonitas[posLibre].sigEps = aux;
    }
  }
  if(listaPersonitas[posLibre].p.getNombreEps() == "nueva"){
    if(cabeceraEps[2].head == -1){
      cabeceraEps[2].head = posLibre;
      listaPersonitas[posLibre].sigEps = -1;
    }
    else{
      int aux = cabeceraEps[2].head;  
      cabeceraEps[2].head = posLibre;
      listaPersonitas[posLibre].sigEps = aux;
    }
  }
  if(listaPersonitas[posLibre].p.getNombreEps() == "cafeSalud"){
    if(cabeceraEps[3].head == -1){
      cabeceraEps[3].head = posLibre;
      listaPersonitas[posLibre].sigEps = -1;
    }
    else{
      int aux = cabeceraEps[3].head;  
      cabeceraEps[3].head = posLibre;
      listaPersonitas[posLibre].sigEps = aux;
    }
  }
if(listaPersonitas[posLibre].p.getNombreEps() == "famisanar"){
    if(cabeceraEps[4].head == -1){
      cabeceraEps[4].head = posLibre;
      listaPersonitas[posLibre].sigEps = -1;
    }
    else{
      int aux = cabeceraEps[4].head;  
      cabeceraEps[4].head = posLibre;
      listaPersonitas[posLibre].sigEps = aux;
    }
  }
}

Lista<Persona> Multilista::listaSexo(char sexo){
  Lista<Persona> listaPersona = Lista<Persona>();
  if(sexo == 'm'){
    int aux = cabeceraSexo[0].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigSexo;
    }
  }

  if(sexo == 'f'){
    int aux = cabeceraSexo[1].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigSexo;
    }
  }
  return listaPersona;
}

Lista<Persona> Multilista::listaEdad(int num){
  Lista<Persona> listaPersona = Lista<Persona>();
  if(num == 0){
    int aux = cabeceraEdad[0].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }

  if(num == 1){
    int aux = cabeceraEdad[1].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }

  if(num == 2){
    int aux = cabeceraEdad[2].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }
  if(num == 3){
    int aux = cabeceraEdad[3].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }
  if(num == 4){
    int aux = cabeceraEdad[4].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }
  if(num == 5){
    int aux = cabeceraEdad[5].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }
  if(num == 6){
    int aux = cabeceraEdad[6].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }
  if(num == 7){
    int aux = cabeceraEdad[7].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigEdad;
    }
  }
  return listaPersona;
}

Lista<Persona> Multilista::listaActividad(int num){
  Lista<Persona> listaPersona = Lista<Persona>();
  if(num == 0){
    int aux = cabeceraActividad[0].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigActividad;
    }
  }
   if(num == 1){
    int aux = cabeceraActividad[1].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigActividad;
    }
  }
  if(num == 2){
    int aux = cabeceraActividad[2].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigActividad;
    }
  }
  if(num == 3){
    int aux = cabeceraActividad[3].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigActividad;
    }
  }
  if(num == 4){
    int aux = cabeceraActividad[4].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigActividad;
    }
  }
  if(num == 5){
    int aux = cabeceraActividad[5].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigActividad;
    }
  }
  return listaPersona;
}
  
Lista<Persona> Multilista::listaPaisN(int num){
  Lista<Persona> listaPersona = Lista<Persona>();
  if(num == 0){
    int aux = cabeceraPaisN[0].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigPaisN;
    }
  }
  if(num == 1){
    int aux = cabeceraPaisN[1].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigPaisN;
    }
  }
  if(num == 2){
    int aux = cabeceraPaisN[2].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigPaisN;
    }
  }
  if(num == 3){
    int aux = cabeceraPaisN[3].head;
    while(aux != -1){
      listaPersona.insertarInicio(listaPersonitas[aux].p);
      aux = listaPersonitas[aux].sigPaisN;
    }
  }
  return listaPersona;
}

Lista<Persona> Multilista::listaCiudadR(int num){
  Lista<Persona> listaPersona = Lista<Persona>();
  if(num == 0){
      int aux = cabeceraCiudadR[0].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigCiudadR;
      }
    }
    if(num == 1){
      int aux = cabeceraCiudadR[1].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigCiudadR;
      }
    }
    if(num == 2){
      int aux = cabeceraCiudadR[2].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigCiudadR;
      }
    }
    if(num == 3){
      int aux = cabeceraCiudadR[3].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigCiudadR;
      }
    }
  return listaPersona;
}


Lista<Persona> Multilista::listaEps(int num){
  Lista<Persona> listaPersona = Lista<Persona>();
  if(num == 0){
      int aux = cabeceraEps[0].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigEps;
      }
    }
    if(num == 1){
      int aux = cabeceraEps[1].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigEps;
      }
    }
    if(num == 2){
      int aux = cabeceraEps[2].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigEps;
      }
    }
    if(num == 3){
      int aux = cabeceraEps[3].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigEps;
      }
    }
    if(num == 4){
      int aux = cabeceraEps[4].head;
      while(aux != -1){
        listaPersona.insertarInicio(listaPersonitas[aux].p);
        aux = listaPersonitas[aux].sigEps;
      }
    }
  return listaPersona;
}
#endif
