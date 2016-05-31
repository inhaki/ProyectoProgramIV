#ifndef Vuelo_h
#define Vuelo_h

#include <iostream>
#include <stdio.h>
#include <string.h>
    
    class Trayecto
    {
    private:
    
        int cod_V;
        std::string aero_Orig;
        std::string aero_Dest;
        int fecha;
        int hora_Sal;
        int hora_Lleg;
        int precio;
        
    public:
        Trayecto(int cod_V, std::string aero_Orig, std::string aero_Dest, int fecha, int hora_Sal, int hora_Lleg, int precio);
        Trayecto();
        ~Trayecto();

        int crearTrayecto();
        
        int getcod_V() const;
        std::string getAeroO() const;
        std::string getAeroD() const;
        int getFecha() const;
        int getHoraS() const;
        int getHoraL() const;
        int getPre() const;
    };
    
    class Avion
    {
    private:
        
        int cod_A;
        std::string nom_compania;
        int asientos;
        
    public:
        
        Avion(int cod_A, std::string nom_compania, int asientos);
        Avion();
        ~Avion();

        int anadirAvion();
        
        int getcod_A() const;
        std::string getNomC() const;
        int getAsiento() const;
        
    };

#endif