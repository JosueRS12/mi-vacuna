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


    cout<<"hola gonorreas"<<endl;
    // File pointer
    fstream fin;
    Pila<string> pila;
    char sexo[1];
  
    // Open an existing file
    fin.open("./files/persona.csv", ios::in);
    cout<<"hola gonorreas 2.0"<<endl;
  
    // Read the Data from the file
    // as String Vector
    string line, word, temp;
    //!fin.eof() 
    while (!fin.eof()){ //cada vez que se ejecuta, lee una fila del csv
        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
  
        // used for breaking words
        stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        cout<<"line: "<<line<<endl;
        while (getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            pila.push(word);
            cout<<"word: "<<word<<endl;
        }
  
        cout<<"cualquier cosa "<<endl;
        persona.getFechaSegundaD().setYear( stoi(pila.pop()) );
        persona.getFechaSegundaD().setMonth( stoi(pila.pop()) ); 
        persona.getFechaSegundaD().setDay( stoi(pila.pop()) ); 
        persona.getFechaPrimeraD().setYear( stoi(pila.pop()) ); 
        persona.getFechaPrimeraD().setMonth( stoi(pila.pop()) ); 
        persona.getFechaPrimeraD().setDay( stoi(pila.pop()) ); 
        persona.getFechaN().setYear( stoi(pila.pop()) ); 
        persona.getFechaN().setMonth( stoi(pila.pop()) ); 
        persona.getFechaN().setDay( stoi(pila.pop()) ); //misdudas
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
        //arbolRN.ins_arbol(persona.getNumeroId(),persona);
    }
    cout<<"salido fichero"<<endl;
