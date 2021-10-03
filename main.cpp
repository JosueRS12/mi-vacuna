#include <iostream>
#include <cstdlib>
#include <wchar.h>
#include "./views/usuarioNuevo.h"
//#include <./view>
  //cout.fill('-');
  //cout<<setw(15)<<" holaaa"<<endl;
  //cout<<setw(15)<<" holaaa"<<endl;
  //gotoxy(x,y);
using namespace std;
int main (){
  int op,op2,op3,op4,op5,op6,op7;
  do{
    cout<<"Mi Vacuna"<<endl;
    cout<<"Bienvenido, ¿Bajo que rol ingresa?"<<endl;
    cout<<"Digite la opción deseada"<<endl;
    cout<<"1) Ministerio de salud"<<endl; //controlador ministerio
    cout<<"2) Beneficiario"<<endl; //controlador ben => editar datos, consultar cita vacunación 
    cout<<"3) Nuevo Usuario"<<endl; //controlador nuevo
    cout<<"0) salir"<<endl;
    cin>> op;
    cin.ignore();
    cout<<"\n";
    switch (op){
      case 1:
      {
      }break;
      case 2:
      {

      }break;
      case 3: usuarioNuevo();
      break;
      case 4:
      {

      }break;
      default: cout<<"Saliendo";
        break;
    }
  } while(op!=0);




  ////cout mostrando cargado de datos al sistema satisfactorio
  //cout<<"1) Agregrar usuario al sistema"<<endl;//listo
  //cout<<"2) Modificar usuario al sistema"<<endl;//no modificar clave, fecha nacimiento, nombres, apellidos
  //cout<<"3) Eliminar usuario al sistema"<<endl;
  //cout<<"4) Agregrar ips al sistema"<<endl;
  //cout<<"5) Modificar ips al sistema"<<endl;
  //cout<<"6) Eliminar ips al sistema"<<endl;
  //cout<<"7)"<<endl;

  return 0;
}
