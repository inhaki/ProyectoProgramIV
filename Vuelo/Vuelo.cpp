#include <iostream>
#include <stdio.h>
#include <string.h>
#include "C:\Users\Alumno\ProyectoProgramIV\ProyectoProgramIV\bbdd.cpp"

#include "Vuelo.h"

using namespace std;

DBConnector dbConnector("ProyectoBBDD.s3db");

    int result;

Trayecto::Trayecto(int cod_V, string aero_Orig, string aero_Dest, int fecha, int hora_Sal, int hora_Lleg, int precio)
{
    cout << "Constructor Trayecto" << endl;
    this->cod_V = cod_V;
    this->aero_Orig = aero_Orig;
    this->aero_Dest = aero_Dest;
    this->fecha = fecha;
    this->hora_Sal = hora_Sal;
    this->hora_Lleg = hora_Lleg;
    this->precio = precio;
}

Trayecto::Trayecto(){}//constructor vacío, para poder instanciar objetos vacíos


Trayecto::~Trayecto()
{
    cout << "Destructor Trayecto" << endl;
}

int Trayecto::crearTrayecto(){
    int cod_V, fecha, hora_Sal, hora_Lleg, precio;
    string aero_Orig;
    string aero_Dest;
    
    cout<<"Introduzca el codigo del Trayecto: ";
    cin>>cod_V;
    cout<<"Introduzca el aeropuerto Origen: ";
    cin>>aero_Orig;
    cout<<"Introduzca el aeropuerto Destino: ";
    cin>>aero_Dest;
    cout<<"Introduzca la fecha programada: ";
    cin>>fecha;
    cout<<"Introduzca la hora de salida: ";
    cin>>hora_Sal;
    cout<<"Introduzca la hora de llegada: ";
    cin>>hora_Lleg;
    cout<<"Introduzca el precio del ticket: ";
    cin>>precio;

    result= dbConnector.insertNewFlight(cod_V, aero_Orig, aero_Dest, fecha, hora_Sal, hora_Lleg, precio);
    if (result != SQLITE_OK) {
        printf("Error inserting new data\n");
        return result;
    }
}

int Trayecto::getcod_V() const
{
    return this->cod_V;
}

string Trayecto::getAeroO() const
{
    return this->aero_Orig;
}

string Trayecto::getAeroD() const
{
    return this->aero_Dest;
}

int Trayecto::getFecha() const
{
    return this->getFecha();
}

int Trayecto::getHoraS() const
{
    return this->getHoraL();  
}

int Trayecto::getHoraL() const
{
    return this->hora_Lleg;
}

int Trayecto::getPre() const
{
    return this->getHoraS();
}

Avion::Avion(int cod_A, string nom_compania, int asientos)
{
    cout << "Constructor Avion" << endl;
    this->cod_A = cod_A;
    this->nom_compania = nom_compania;
    this->asientos = asientos;   
}

Avion::Avion(){}//constructor vacío, para poder instanciar objetos vacíos

Avion::~Avion()
{
    cout << "Destructor Avion" << endl;   
}

int Avion::anadirAvion(){

    int cod_A, asientos;
    string nom_compania;

    cout<<"Introduzca el identificador del Avion: ";
    cin>>cod_A;
    cout<<"Introduzca la compania a la que pertenece: ";
    cin>>nom_compania;
    cout<<"Introduzca el numero de asientos de la aeronave: ";
    cin>>asientos;

    result = dbConnector.insertNewPlane(cod_A, nom_compania, asientos);
    if (result != SQLITE_OK) {
        printf("Error inserting new data\n");
        return result;
    }
}

int Avion::getcod_A() const
{
    return this->getcod_A();   
}

string Avion::getNomC() const
{
    return this->getNomC();   
}

int Avion::getAsiento() const
{
    return this->getAsiento();    
}