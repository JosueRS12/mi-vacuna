#include <iostream>
#include <cstdlib>
#include <wchar.h>
#include <locale.h>
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
    switch (op){
      case 1:
      {

      }break;
      case 2:
      {

      }break;
      case 3:
      {
        cout<<"Digite el nombre"<<endl;
        cout<<"Digite el apellido"<<endl;
        cout<<"Digite el tipo de identificación"<<endl;
        cout<<"Digite el numero de identificación"<<endl;
        cout<<"Digite el sexo (M/f)"<<endl;
        cout<<"Digite el celular"<<endl;
        cout<<"Digite el numero fijo"<<endl;
        cout<<"Digite el correo electrónico"<<endl;
        cout<<"Digite la fecha de nacimiento"<<endl;
        cout<<"Digite la ciudad de nacimiento"<<endl;
        cout<<"Digite el país de nacimiento"<<endl;
        cout<<"Digite la ciudad de residencia"<<endl;
        cout<<"Digite la dirección"<<endl;
        cout<<"Digite el barrio"<<endl;
        cout<<"Selecciona la actividad laboral en la que se desempeña"<<endl;
        cout<<"1) Artes"<<endl;
        cout<<"2) Ingenieria"<<endl;
        cout<<"3) Ciencias Sociales"<<endl;
        cout<<"4) Areas de la Salud"<<endl;
        cout<<"5) otros"<<endl;
        cin>>op2;
        switch (op2){
          case 1:
            {
          
            }break;
          case 2:
            {

            }break;
          case 3:
            {

            }break;
          case 4:
            {
            }break;
          case 5:
            {
            }break;
          default:
              ///otros
            break;
        }
        cout<<"Seleccione el nombre de la eps"<<endl;
        cout<<"1) Compensar"<<endl;
        cout<<"2) Sanitas"<<endl;
        cout<<"3) Nueva "<<endl;
        cout<<"4) Cafe Salud"<<endl;
        cout<<"5) Famisanar "<<endl;
        cin>>op3;
        switch (op3){
          case 1:
            {
          
            }break;
          case 2:
            {

            }break;
          case 3:
            {

            }break;
          case 4:
            {
            }break;
          case 5:
            {
            }break;
          default:
            break;
        }
        cout<<"Seleccione el tipo vacuna"<<endl;
        cout<<"1) Pfizer "<<endl;
        cout<<"2) Aztrazeneca"<<endl;
        cout<<"3) Johnson"<<endl;
        cout<<"4) Moderna"<<endl;
        cout<<"5) Sputnik "<<endl;
        cout<<"6) Sinovac "<<endl;
        cin>>op3;
        switch (op3){
          case 1:
            {
            }break;
          case 2:
            {

            }break;
          case 3:
            {

            }break;
          case 4:
            {
            }break;
          case 5:
            {
            }break;
          case 6:
            {
            }break;
          default:
            break;
        }
        cout<<"Digite la fecha de primera dosis"<<endl; // opcinal
        cout<<"Digite la fecha de segunda dosis"<<endl; //opcional
      }break;
      case 4:
      {

      }break;
      default: cout<<"Saliendo";
        break;
    }
  } while(op!=0);




  //cout mostrando cargado de datos al sistema satisfactorio
  cout<<"1) Agregrar usuario al sistema"<<endl;//listo
  cout<<"2) Modificar usuario al sistema"<<endl;//no modificar clave, fecha nacimiento, nombres, apellidos
  cout<<"3) Eliminar usuario al sistema"<<endl;
  cout<<"4) Agregrar ips al sistema"<<endl;
  cout<<"5) Modificar ips al sistema"<<endl;
  cout<<"6) Eliminar ips al sistema"<<endl;
  cout<<"7)"<<endl;

  return 0;
}
