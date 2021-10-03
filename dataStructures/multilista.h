#ifndef MULTILISTA_H
#define MULTILISTA_H

//insertarOrdenado
#include <iostream>
#include <cstdlib>
#include "../models/Persona.h"
#include "lista.h"
//#include <ctime>

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
  ~Multilista(); //implementar nice
  void insertarPersonita(Personita delSenior);
  void ordenarSexo(Personita delSenior);
  void ordenarEdad(Personita delSenior);
  void ordenarActividad(Personita delSenior);
  void ordenarPaisN(Personita delSenior);
  void ordenarCiudadR(Personita delSenior);
  void ordenarEps(Personita delSenior);
  //bool eliminar();
  void buscarListaNombre();
  void buscarListaEdad();
  void buscarListaHobby(string tipo);
  void buscarListaCarrera(string tipo);
  bool vacio();
  bool lleno();
};

void Multilista :: insertarPersonita(Personita delSenior){
  ordenarSexo(delSenior);
  ordenarActividad(delSenior);
  //insertarCarrera(es);
  //insertarEdad(es);
  //insertarHobby(es);
  listaPersonitas.insertarInicio(delSenior);
}

void Multilista :: ordenarSexo(Personita delSenior){
  Personita *aux = new Personita(); //funciona
  if(delSenior.p->getSexo() == 'm'){
    if(cabeceraSexo[0].head == NULL)
      cabeceraSexo[0].head = &delSenior;
    else{
      aux = cabeceraSexo[0].head; 
      cabeceraSexo[0].head = &delSenior;
      delSenior.sigSexo = aux; 
    }
  }
  if(delSenior.p->getSexo() == 'f'){
    if(cabeceraSexo[1].head == NULL)
      cabeceraSexo[1].head = &delSenior;
    else{
      aux = cabeceraSexo[1].head; 
      cabeceraSexo[1].head = &delSenior;
      delSenior.sigSexo = aux; 
    }
  }
}

void Multilista :: ordenarEdad(Personita delSenior){
  //Personita *aux = new Personita(); //funciona
  //if(delSenior.p->getEdad() == 'm'){
    //if(cabeceraSexo[0].head == NULL)
      //cabeceraSexo[0].head = &delSenior;
    //else{
      //aux = cabeceraSexo[0].head; 
      //cabeceraSexo[0].head = &delSenior;
      //delSenior.sigSexo = aux; 
    //}
  //}
  //if(delSenior.p->getSexo() == 'f'){
    //if(cabeceraSexo[1].head == NULL)
      //cabeceraSexo[1].head = &delSenior;
    //else{
      //aux = cabeceraSexo[1].head; 
      //cabeceraSexo[1].head = &delSenior;
      //delSenior.sigSexo = aux; 
    //}
  //}
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
    //cabeceraPaisN[0] = {NULL, "colombia"};
    //cabeceraPaisN[1] = {NULL, "francia"};
    //cabeceraPaisN[2] = {NULL, "venezuela"};
    //cabeceraPaisN[3] = {NULL, "brasil"};
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

void ordenarEps(Personita delSenior);
  
//void Multilista::buscarListaNombre(){
  //int i = 0;
  //Estudiante *nodo = cabeceras[4].head;
  
  //while(nodo != NULL){
    //cout<<i<<" "<<nodo -> nombre<<" "<<nodo->carrera<<endl;
    //i++;
    //nodo = nodo -> sigNombre;
  //}
//}

//void Multilista::buscarListaEdad(){
  //int i = 0;
  //Estudiante *nodo = cabeceras[5].head;
  
  //while(nodo != NULL){
    //cout<<i<<" "<<nodo -> nombre<<" "<<nodo->carrera<<endl;
    //i++;
    //nodo = nodo -> sigEdad;
  //}
//}

//void Multilista::buscarListaCarrera(string tipo){
  //int i = 0;
  
  //while(cabeceras[i].tipo != tipo)
   //i++;
  //Estudiante *nodo = cabeceras[i].head;

  //while(nodo != NULL){
    //cout<<i<<" "<<nodo -> nombre<<" "<<nodo -> edad<<" "<<nodo->carrera<<" "<< nodo -> hobby <<endl;
    //i++;
    //nodo = nodo -> sigCarrera;
  //}
//}

//void Multilista::buscarListaHobby(string tipo){
  //int i = 0;
  //while(cabeceras[i].tipo != tipo)
   //i++;
  //Estudiante *nodo = cabeceras[i].head;
  
  //i=0;
  //while(nodo -> sigHobby != NULL){
    //cout<<i<<" "<<nodo -> nombre<<" "<<nodo->carrera<<endl;
    //i++;
    //nodo = nodo -> sigHobby;
  //}
//}


//void Multilista::insertarCarrera(Estudiante es){
  //int i = 0;
  //Estudiante *nodo = new Estudiante, *anterior = new Estudiante;
  //*nodo =es; 
  //while(cabeceras[i].tipo != nodo ->carrera)
   //i++;
  
	//nodo -> sigCarrera = NULL;
	//Estudiante *aux = cabeceras[i].head;
	//while(aux != NULL){
    //anterior = aux;
		//aux = aux -> sigCarrera; //ultimo

	//}
  //nodo -> sigCarrera = NULL;

  //if(cabeceras[i].head != NULL){
    //anterior -> sigCarrera = nodo;
  //}else{
    //cabeceras[i].head = nodo;
  //} 
//}

//void Multilista :: insertarNombre(Estudiante es){
  //Estudiante *anterior, *nodo = new Estudiante;
  //*nodo =es;   
  //Estudiante *p = cabeceras[4].head;  
  //anterior = cabeceras[4].head;

  //while(p != NULL){ 
    //if(p -> nombre > nodo ->nombre)
      //break; //- > se obtiene el mayor o se obtiene el ultimo (z)
    //anterior = p; 
    //p = p -> sigNombre;
	 
  //}
  //nodo ->sigNombre = p;
  //if(cabeceras[4].head != NULL){
    //anterior -> sigNombre = nodo;
  //}else{
    //cabeceras[4].head = nodo;
  //} 
//}

//void Multilista :: insertarEdad(Estudiante es){
  //Estudiante *anterior, *nodo = new Estudiante, *p = new Estudiante;
  //*nodo =es;   
  //p = cabeceras[5].head;  
  //anterior = cabeceras[5].head;

  //while(p != NULL){ 
    //cout<<"entra edad"<<endl;
    //if(p -> edad <= nodo -> edad)
      //break; //- > se obtiene el mayor o se obtiene el ultimo (z)
    //anterior = p; 
    //p = p -> sigEdad;
  //}

  //nodo ->sigEdad = p;
  //if(cabeceras[5].head != NULL){
    //anterior -> sigEdad = nodo;
  //}else{
    //cabeceras[5].head = nodo;
  //} 
//}

//void Multilista::insertarHobby(Estudiante es){
  //int i = 0;
  //while(cabeceras[i].tipo != es.hobby)
   //i++;
  
  //Estudiante *nodo = &es; //funciona
  //nodo -> sigHobby = cabeceras[i].head;
  //cabeceras[i].head = nodo;
//}

//bool Multilista::vacio(){
  //if(tam == 0)
    //return true;
  //else
    //return false;
//}

//bool Multilista::lleno(){
  //if(tam == sizeof(estudiantes))
    //return true;
  //else
    //return false;
//}

#endif
