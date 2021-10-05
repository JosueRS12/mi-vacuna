#ifndef IPS_H
#define IPS_H

#include <iostream>
#include <cstdlib>

using namespace std;

struct Vacuna{
  string nombreVacuna;
  int cantidad;
};

class Ips{
  string nombre;
  string direccion;
  string ciudad;
  Vacuna *arrayVacunas;
  public:
  Ips(){
    nombre = " ";
    direccion = " ";
    ciudad = " ";
    arrayVacunas = new Vacuna[6];
    arrayVacunas[0] = {"pfizer",0};
    arrayVacunas[1] = {"moderna",0};
    arrayVacunas[2] = {"sputnik",0};
    arrayVacunas[3] = {"astrazeneca",0};
    arrayVacunas[4] = {"johnson",0};
    arrayVacunas[5] = {"sinovac",0};
  } 
  void vacunaPfizer(int);
  void vacunaModerna(int);
  void vacunaSputnik(int);
  void vacunaAstrazeneca(int);
  void vacunaJohnson(int);
  void vacunaSinovac(int);
  Vacuna *getVacuna();
  string getNombre();
  void setNombre(string nombre);
  string getDireccion();
  void setDireccion(string direccion);
  string getCiudad();
  void setCiudad(string ciudad);

};

Vacuna *Ips:: getVacuna(){
  return arrayVacunas;
}

string  Ips::getNombre() {
    return nombre;
}

void  Ips::setNombre(string nombre) {
    this->nombre = nombre;
}

string  Ips::getDireccion() {
    return direccion;
}

void  Ips::setDireccion(string direccion) {
    this->direccion = direccion;
}

string  Ips::getCiudad() {
    return ciudad;
}

void Ips::setCiudad(string ciudad) {
    this->ciudad = ciudad;
}

void Ips::vacunaPfizer(int c){
  this->arrayVacunas[0] = {"pfizer",c};
}
void Ips::vacunaModerna(int c){
  this->arrayVacunas[1] = {"moderna",c};
}
void Ips::vacunaSputnik(int c){
  this->arrayVacunas[2] = {"sputnik",c};
}
void Ips::vacunaAstrazeneca(int c){
  this->arrayVacunas[3] = {"astrazeneca",c};
}
void Ips::vacunaJohnson(int c){
  this->arrayVacunas[4] = {"johnson",c};
}
void Ips::vacunaSinovac(int c){
  this->arrayVacunas[5] = {"sinovac",c};
}

#endif
