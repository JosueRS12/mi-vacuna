#ifndef CONSULTAS_H
#define CONSULTAS_H
#include "../dataStructures/lista.h"
#include "../models/Persona.h"




//eps y rango de edad
int *consulta1(Lista<Persona> lista){ //lista rango 0, 1, 2, 3, 4 ...
  int *eps = new int[5]; 
  eps[0] = 0;
  eps[1] = 0;
  eps[2] = 0;
  eps[3] = 0;
  eps[4] = 0;
  eps[5] = 0;
  Nodo<Persona> *p = lista.getHead();
  //[<20,20-25,5,92123]
  while(p!=NULL){
    if(p->info.getNombreEps() == "compensar"){
      eps[0]+=1;
    }
    if(p->info.getNombreEps() == "sanitas"){
      eps[1]++;
    }
    if(p->info.getNombreEps() == "nueva"){
      eps[2]++;
    }
    if(p->info.getNombreEps() == "cafeSalud"){
      eps[3]++;
    }
    if(p->info.getNombreEps() == "famisanar"){
      eps[4]++;
    }
    p=p->sig;
  }
  return eps;
}





#endif
