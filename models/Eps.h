#ifndef EPS_H
#define EPS_H
#include <iostream>
#include <cstdlib>
#include "../dataStructures/lista.h"
#include "./Ips.h"
using namespace std;

class Eps{
  string nombre;
  Vacuna *vacunasMedellin;
  Vacuna *vacunasBogota;
  Vacuna *vacunasBarranquilla;
  Vacuna *vacunasCali;
  Lista<Ips> listaIps;
  public:
  Eps(){
    nombre = " ";
    vacunasMedellin = new Vacuna[6];
    vacunasBogota= new Vacuna[6];
    vacunasBarranquilla= new Vacuna[6];
    vacunasCali= new Vacuna[6];
    vacunasMedellin[0] = {"pfizer",0};
    vacunasMedellin[1] = {"moderna",0};
    vacunasMedellin[2] = {"sputnik",0};
    vacunasMedellin[3] = {"astrazeneca",0};
    vacunasMedellin[4] = {"johnson",0};
    vacunasMedellin[5] = {"sinovac",0};
    vacunasBogota[0] = {"pfizer",0};
    vacunasBogota[1] = {"moderna",0};
    vacunasBogota[2] = {"sputnik",0};
    vacunasBogota[3] = {"astrazeneca",0};
    vacunasBogota[4] = {"johnson",0};
    vacunasBogota[5] = {"sinovac",0};
    vacunasBarranquilla[0] = {"pfizer",0};
    vacunasBarranquilla[1] = {"moderna",0};
    vacunasBarranquilla[2] = {"sputnik",0};
    vacunasBarranquilla[3] = {"astrazeneca",0};
    vacunasBarranquilla[4] = {"johnson",0};
    vacunasBarranquilla[5] = {"sinovac",0};
    vacunasCali[0] = {"pfizer",0};
    vacunasCali[1] = {"moderna",0};
    vacunasCali[2] = {"sputnik",0};
    vacunasCali[3] = {"astrazeneca",0};
    vacunasCali[4] = {"johnson",0};
    vacunasCali[5] = {"sinovac",0};
  } 
  void vacunaPfizer(int);
  void vacunaModerna(int);
  void vacunaSputnik(int);
  void vacunaAstrazeneca(int);
  void vacunaJohnson(int);
  void vacunaSinovac(int);
  Vacuna *getVacunaMedellin();
  Vacuna *getVacunaBogota();
  Vacuna *getVacunaBarranquilla();
  Vacuna *getVacunaCali();
  string getNombre();
  void setNombre(string nombre);
  string getDireccion();
  void setDireccion(string direccion);
  string getCiudad();
  void setCiudad(string ciudad);
  void vacunaMedellinPfizer(int c);
  void vacunaMedellinModerna(int c);
  void vacunaMedellinSputnik(int c);
  void vacunaMedellinAstrazeneca(int c);
  void vacunaMedellinJohnson(int c);
  void vacunaMedellinSinovac(int c);
  void vacunaBogotaPfizer(int c);
  void vacunaBogotaModerna(int c);
  void vacunaBogotaSputnik(int c);
  void vacunaBogotaAstrazeneca(int c);
  void vacunaBogotaJohnson(int c);
  void vacunaBogotaSinovac(int c);
  void vacunaBarranquillaPfizer(int c);
  void vacunaBarranquillaModerna(int c);
  void vacunaBarranquillaSputnik(int c);
  void vacunaBarranquillaAstrazeneca(int c);
  void vacunaBarranquillaJohnson(int c);
  void vacunaBarranquillaSinovac(int c);
  void vacunaCaliPfizer(int c);
  void vacunaCaliModerna(int c);
  void vacunaCaliSputnik(int c);
  void vacunaCaliAstrazeneca(int c);
  void vacunaCaliJohnson(int c);
  void vacunaCaliSinovac(int c);
};

Vacuna *Eps:: getVacunaMedellin(){
  return this->vacunasMedellin;
}

 Vacuna *Eps:: getVacunaBogota(){
  return this->vacunasBogota;
}

Vacuna *Eps:: getVacunaBarranquilla(){
  return this->vacunasBarranquilla;
}

Vacuna *Eps:: getVacunaCali(){
  return this->vacunasCali;
}

string  Eps::getNombre() {
    return nombre;
}

void  Eps::setNombre(string nombre) {
    this->nombre = nombre;
}

void Eps::vacunaMedellinPfizer(int c){
  this->vacunasMedellin[0] = {"pfizer",c};
}
void Eps::vacunaMedellinModerna(int c){
  this->vacunasMedellin[1] = {"moderna",c};
}
void Eps::vacunaMedellinSputnik(int c){
  this->vacunasMedellin[2] = {"sputnik",c};
}
void Eps::vacunaMedellinAstrazeneca(int c){
  this->vacunasMedellin[3] = {"astrazeneca",c};
}
void Eps::vacunaMedellinJohnson(int c){
  this->vacunasMedellin[4] = {"johnson",c};
}
void Eps::vacunaMedellinSinovac(int c){
  this->vacunasMedellin[5] = {"sinovac",c};
}
void Eps::vacunaBogotaPfizer(int c){
  this->vacunasBogota[0] = {"pfizer",c};
}
void Eps::vacunaBogotaModerna(int c){
  this->vacunasBogota[1] = {"moderna",c};
}
void Eps::vacunaBogotaSputnik(int c){
  this->vacunasBogota[2] = {"sputnik",c};
}
void Eps::vacunaBogotaAstrazeneca(int c){
  this->vacunasBogota[3] = {"astrazeneca",c};
}
void Eps::vacunaBogotaJohnson(int c){
  this->vacunasBogota[4] = {"johnson",c};
}
void Eps::vacunaBogotaSinovac(int c){
  this->vacunasBogota[5] = {"sinovac",c};
}
void Eps::vacunaBarranquillaPfizer(int c){
  this->vacunasBarranquilla[0] = {"pfizer",c};
}
void Eps::vacunaBarranquillaModerna(int c){
  this->vacunasBarranquilla[1] = {"moderna",c};
}
void Eps::vacunaBarranquillaSputnik(int c){
  this->vacunasBarranquilla[2] = {"sputnik",c};
}
void Eps::vacunaBarranquillaAstrazeneca(int c){
  this->vacunasBarranquilla[3] = {"astrazeneca",c};
}
void Eps::vacunaBarranquillaJohnson(int c){
  this->vacunasBarranquilla[4] = {"johnson",c};
}
void Eps::vacunaBarranquillaSinovac(int c){
  this->vacunasBarranquilla[5] = {"sinovac",c};
}
void Eps::vacunaCaliPfizer(int c){
  this->vacunasCali[0] = {"pfizer",c};
}
void Eps::vacunaCaliModerna(int c){
  this->vacunasCali[1] = {"moderna",c};
}
void Eps::vacunaCaliSputnik(int c){
  this->vacunasCali[2] = {"sputnik",c};
}
void Eps::vacunaCaliAstrazeneca(int c){
  this->vacunasCali[3] = {"astrazeneca",c};
}
void Eps::vacunaCaliJohnson(int c){
  this->vacunasCali[4] = {"johnson",c};
}
void Eps::vacunaCaliSinovac(int c){
  this->vacunasCali[5] = {"sinovac",c};
}
