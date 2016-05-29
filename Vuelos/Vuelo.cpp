

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Vuelo.h"

using namespace std;

Trayecto::Trayecto(int cod_V, std::string aero_Orig, std::string aero_Dest, int fecha, int hora_Sal, int hora_Lleg, int precio)
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

Trayecto::~Trayecto()
{
    cout << "Destructor Trayecto" << endl;

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

Avion::~Avion()

{
    
    cout << "Destructor Avion" << endl;
    
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


