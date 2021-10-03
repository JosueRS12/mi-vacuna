#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstdlib>
#include "date.h"

using namespace std;

class Persona{
  string nombre;
  string apellido;
  string tipoId;
  int numeroId;
  char sexo;
  string celular;
  string fijo;
  string correo;
  string CiudadN;
  string paisN;
  string ciudadR; 
  string direccion;
  string barrio;
  string actividad;
  string nombreEps;
  string tipoVacuna;
  Date fechaN;
  Date fechaPrimeraD;
  Date fechaSegundaD;

  public:
  Persona();
  string getNombre();
  void setNombre(string nombre); 
  string getApellido(); 
  void setApellido(string apellido);
  string getTipoId(); 
  void setTipoId(string tipoId);
  int getNumeroId(); 
  void setNumeroId(int numeroId);
  char getSexo(); 
  void setSexo(char sexo);
  string getCelular();
  void setCelular(string celular);
  string getFijo(); 
  void setFijo(string fijo); 
  string getCorreo();
  void setCorreo(string correo);
  string getCiudadN();
  void setCiudadN(string CiudadN);
  string getPaisN();
  void setPaisN(string paisN); 
  string getCiudadR();
  void setCiudadR(string ciudadR);
  string getDireccion(); 
  void setDireccion(string direccion);
  string getBarrio(); 
  void setBarrio(string barrio); 
  string getActividad(); 
  void setActividad(string actividad); 
  string getNombreEps(); 
  void setNombreEps(string nombreEps); 
  string getTipoVacuna(); 
  void setTipoVacuna(string tipoVacuna); 
  void setFechaN(Date date); 
  Date getFechaN(); 
  void setFechaPrimeraD(Date date); 
  Date getFechaPrimeraD(); 
  void setFechaSegundaD(Date date); 
  Date getFechaSegundaD(); 
};

Persona :: Persona(){

}

string Persona :: getNombre() {
  return nombre;
}

void Persona :: setNombre(string nombre) {
    this->nombre = nombre;
}

string Persona :: getApellido() {
    return apellido;
}

void Persona :: setApellido(string apellido) {
    this->apellido = apellido;
}

string Persona :: getTipoId() {
    return tipoId;
}

void Persona ::  setTipoId(string tipoId) {
    this->tipoId = tipoId;
}

int Persona :: getNumeroId() {
    return numeroId;
}

void Persona :: setNumeroId(int numeroId) {
    this->numeroId = numeroId;
}

char Persona ::  getSexo() {
    return sexo;
}

void Persona :: setSexo(char sexo) {
    this->sexo = sexo;
}

string Persona :: getCelular() {
    return celular;
}

void Persona :: setCelular(string celular) {
    this->celular = celular;
}

string Persona :: getFijo() {
    return fijo;
}

void Persona :: setFijo(string fijo) {
    this->fijo = fijo;
}

string Persona :: getCorreo() {
    return correo;
}

void Persona :: setCorreo(string correo) {
    this->correo = correo;
}

string Persona :: getCiudadN() {
    return CiudadN;
}

void Persona :: setCiudadN(string CiudadN) {
    this->CiudadN = CiudadN;
}

string Persona :: getPaisN() {
    return paisN;
}

void Persona :: setPaisN(string paisN) {
    this->paisN = paisN;
}

string Persona :: getCiudadR() {
    return ciudadR;
}

void Persona :: setCiudadR(string ciudadR) {
    this->ciudadR = ciudadR;
}

string Persona ::  getDireccion() {
    return direccion;
}

void Persona :: setDireccion(string direccion) {
    this->direccion = direccion;
}

string Persona :: getBarrio() {
    return barrio;
}

void Persona :: setBarrio(string barrio) {
    this->barrio = barrio;
}

string Persona :: getActividad() {
    return actividad;
}

void Persona :: setActividad(string actividad) {
    this->actividad = actividad;
}

string Persona :: getNombreEps() {
    return nombreEps;
}

void Persona :: setNombreEps(string nombreEps) {
    this->nombreEps = nombreEps;
}

string Persona :: getTipoVacuna() {
    return tipoVacuna;
}

void Persona :: setTipoVacuna(string tipoVacuna) {
    this->tipoVacuna = tipoVacuna;
}

void Persona :: setFechaN(Date date) {
  this->fechaN = date;
}

Date Persona :: getFechaN() {
  return fechaN;
}

void Persona :: setFechaPrimeraD(Date date) {
  this->fechaPrimeraD = date;
}

Date Persona :: getFechaPrimeraD() {
  return fechaPrimeraD;
}

void Persona :: setFechaSegundaD(Date date) {
  this->fechaSegundaD = date;
}

Date Persona :: getFechaSegundaD(){
  return fechaSegundaD;
}

#endif
