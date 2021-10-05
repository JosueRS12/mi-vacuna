#include <iostream>
#include <cstdlib>
#include <wchar.h>
#include "./views/usuarioNuevo.h"
#include "./views/beneficiario.h"
#include "./views/ministerio.h"
#include "./dataStructures/arbolesRN.h"
#include "./models/files/filePersona.h"
#include "./dataStructures/multilista.h"
#include "./models/Persona.h"
//#include <./view>
  //cout.fill('-');
  //cout<<setw(15)<<" holaaa"<<endl;
  //cout<<setw(15)<<" holaaa"<<endl;
  //gotoxy(x,y);
using namespace std;
int main (){
  int op, idClave;
  Multilista *multiPersona = NULL;
  Persona *p=NULL; //=>apuntador persona auxiliar...
  ARBOL<int,Persona> *arbolRN = NULL; //mirar si se puede hacer como apuntador
  FilePersona filePersona;
  Pila<Persona> *pilaPer = NULL;
  arbolRN = filePersona.readFile();

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
        switch(menuMinisterio()){
          case 1:
            {
              multiPersona = simulacion(arbolRN); 
            }
            break;
          case 2://consulta
            break;
          default: cout<<"Que sueño"<<endl;
            break;
        }
      }break;
      case 2:
      {
        cout<<"Digite su numero de identificación"<<endl;
        cin>>idClave;
        p = arbolRN->buscarNodo(idClave);
        switch(menuBeneficiario()){
          case 1:beneficiarioModificar(p); 
            break;
          case 2:beneficiarioEliminar(p);
            break;
          case 3://consultarUsuario
            break;
          default: cout<<"Que sueño"<<endl;
            break;
        }
        //persona
      }break;
      case 3:
      {
        Persona per = usuarioNuevo();
        arbolRN->ins_arbol(per.getNumeroId(), per);
      }
      break;
      default: cout<<"Saliendo";
        break;
    }
  } while(op!=0);
  pilaPer = arbolRN->obtenerPila( arbolRN->raiz_arbol() ); //=> se obtiene pila apartir de un arbol
  filePersona.createFile(*pilaPer);

  return 0;
}
