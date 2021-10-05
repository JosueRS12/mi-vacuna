#include <cstdlib>
#include <iostream>
#include "pila.h"

using namespace std;

int main(){
  Pila<int> pila;
  
  pila.push(9);
  pila.push(1);
  pila.push(8);
  pila.push(2);
  pila.push(7);
  pila.push(6);
  
  while(pila.pilaVacia() == false){
    cout<<pila.pop()<<endl;
  }
  
  cout<<"holaaaaa"<<endl;
}
