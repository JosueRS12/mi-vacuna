#include <iostream>
#include <cstdlib>
#include "../models/filePersona.h"

using namespace std;

int main(){
  Persona pers, pers2;
  //StackList<Persona> pila;
  Pila<Persona> pila;
  //Persona *arr = new Persona[2];

  pers.setNombre("benito");
  pers.setApellido("camelas");
  pers.setNombreEps("fami");
  pers.setNumeroId(123);

  pers2.setNombre("ben");
  pers2.setApellido("came");
  pers2.setNombreEps("fa");
  pers2.setNumeroId(321);

  pila.push(pers);
  pila.push(pers2);
  
  FilePersona file;
  //file.setPila(pila);
  file.createFile(pila);

  return 0;
}
