#ifndef FILEEPS_H
#define FILEEPS_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h> //=>strcpy
#include "../Eps.h"
#include "../../dataStructures/pila.h"

using namespace std;
class FileEps{
  Eps eps; 
  Pila<Eps> pila;
  public:


} 
int main (){
  //open file
  ofstream os("temp.bin", ofstream :: binary);

  //os.write((char *) &conjunto, sizeof(Conjunto)); //no había cambiado el sizeof 
  //os.write((char *) &conjunto2, sizeof(Conjunto)); //no había cambiado el sizeof 
  //os.write((char *) &conjunto3, sizeof(Conjunto)); //no había cambiado el sizeof 
  //os.write((char *) &conjunto4, sizeof(Conjunto)); //no había cambiado el sizeof 

  os.close();

  ifstream is("temp.bin", ifstream :: binary);
  is.read((char *) &con, sizeof(Conjunto));
  while(!is.eof()){
    cout<<"nombre conjunto "<<con.nombre<<endl;
    cout<<"color casa 0 "<<con.arrCasa[0].color<<endl;
    cout<<"color casa 1 "<<con.arrCasa[1].color<<endl;
    cout<<"color casa 2 "<<con.arrCasa[2].color<<endl;
    cout<<"propietario 0 "<<con.arrCasa[0].pro<<endl;
    cout<<"propietario 1"<<con.arrCasa[1].pro<<endl;
    cout<<"propietario 2"<<con.arrCasa[2].pro<<endl;
    is.read((char *) &con, sizeof(Conjunto));
  }
  is.close();
  return 0;
}
#endif
