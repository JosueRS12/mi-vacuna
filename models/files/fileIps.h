#ifndef FILEIPS_H
#define FILEIPS_H
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>       
#include <fstream>
#include <cstdlib>
#include "../../dataStructures/arbolesRN.h"
#include "../../dataStructures/pila.h"
#include "../date.h"
#include "../Persona.h"
using namespace std;

class FilePersona{
  Persona persona;
  ARBOL<int,Persona> arbolRN;
  public:
  FilePersona(){
    persona = Persona(); 
    arbolRN = ARBOL<int,Persona>(); 
  }
  void createFile(Pila<Persona> pila);
  ARBOL<int,Persona> *readFile();
};

void FilePersona :: createFile(Pila<Persona> pila){
    // file pointer
    fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("./files/persona.csv", ios::out); //ios::app => para usar un archivo existente
  
    cout << "Guardando info:"<<endl;
  
    while(pila.pilaVacia()==false){
      persona = pila.pop();
      fout << persona.getNombre() << ","
           << persona.getApellido() << ","
           << persona.getTipoId() << ","
           << persona.getNumeroId() << ","
           << persona.getSexo() << ","
           << persona.getCelular() << ","
           << persona.getFijo() << ","
           << persona.getCorreo() << ","
           << persona.getCiudadN() << ","
           << persona.getPaisN() << ","
           << persona.getCiudadR() << ","
           << persona.getDireccion() << ","
           << persona.getBarrio() << ","
           << persona.getActividad() << ","
           << persona.getNombreEps() << ","
           << persona.getTipoVacuna() << ","
           << persona.getFechaN().getDay() << ","
           << persona.getFechaN().getMonth() << ","
           << persona.getFechaN().getYear() << ","
           << persona.getFechaPrimeraD().getDay() << ","
           << persona.getFechaPrimeraD().getMonth() << ","
           << persona.getFechaPrimeraD().getYear() << ","
           << persona.getFechaSegundaD().getDay() << ","
           << persona.getFechaSegundaD().getMonth() << ","
           << persona.getFechaSegundaD().getYear() << ","
           << "\n";
      cout<<"--------------"<<endl;
    }
}

ARBOL<int,Persona> *FilePersona :: readFile(){
    // File pointer
    ifstream file("./files/persona.csv");
    string line, word;
    Pila<string> pila;
    char sexo[1];
    while(getline(file,line)) {
      stringstream s(line);
      Date date = Date();
      while (getline(s, word, ',')) {

          // add all the column data
          // of a row to a vector
          pila.push(word);
      }
      date.setYear( stoi(pila.pop()) ); //year
      date.setMonth( stoi(pila.pop()) ); //month
      date.setDay( stoi(pila.pop()) ); //day
      persona.setFechaSegundaD(date); 
      date.setYear( stoi(pila.pop()) ); //year
      date.setMonth( stoi(pila.pop()) ); //month
      date.setDay( stoi(pila.pop()) ); //day
      persona.setFechaPrimeraD(date); 

      date.setYear( stoi(pila.pop()) ); //year
      date.setMonth( stoi(pila.pop()) ); //month
      date.setDay( stoi(pila.pop()) ); //day
      persona.setFechaN(date); //month

      persona.setTipoVacuna( pila.pop() ); 
      persona.setNombreEps( pila.pop() ); 
      persona.setActividad( pila.pop() ); 
      persona.setBarrio( pila.pop() ); 
      persona.setDireccion( pila.pop() ); 
      persona.setCiudadR( pila.pop() ); 
      persona.setPaisN( pila.pop() ); 
      persona.setCiudadN( pila.pop() ); 
      persona.setCorreo( pila.pop() ); 
      persona.setFijo( pila.pop() ); 
      persona.setCelular( pila.pop() ); 
      strcpy(sexo, pila.pop().c_str());
      persona.setSexo(sexo[0]); 
      persona.setNumeroId( stoi(pila.pop()) ); 
      persona.setTipoId( pila.pop() ); 
      persona.setApellido( pila.pop() ); 
      persona.setNombre( pila.pop() );
    
      arbolRN.ins_arbol(persona.getNumeroId(),persona);
    }
    cout<<"salido fichero"<<endl;
    return &arbolRN;
}
#endif
