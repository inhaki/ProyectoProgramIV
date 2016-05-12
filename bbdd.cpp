#include "sqlite3/sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class DBConnector{
	//clase de la bbdd

	private:
		private sqlite3 *db = NULL;

	public:

		//metodo para insertar un nuevo trayecto
		int insertNewFlight(int cod_V, std::string aero_Orig, std::string aero_Dest, int fecha, int hora_Sal, int hora_Lleg, float precio)
		{

		}

		//metodo para insertar un nuevo avion
		int insertNewPlane()
		{
			
		}

		//construcctor el dbFile es el parámtero que pasamos al llamar al método en el DBConnector
		DBConnector(std::string dbFile) {
			int result = sqlite3_open("PacMazeBD.sqlite", &db);
			if (result != SQLITE_OK) {
				printf("Error opening database\n");

			}
		}

		//destructor para cerrar la base de datos (en el close solo pide el puntero que es db)
		~DBConnector() {
			int result = sqlite3_close(db);
			if (result != SQLITE_OK) {
				printf("Error opening database\n");
				printf("%s\n", sqlite3_errmsg(db));
			}	
		}
};