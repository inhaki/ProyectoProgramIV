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
			sqlite3_stmt *stmt;

			char sql[]= "insert into Trayecto (cod_V, aero_Orig, aero_Dest, fecha, hora_Sal, hora_Lleg, precio) values (?, ?, ?, ?, ?, ?, ?)";
			int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL );
			if(result != SQLITE_OK){
				printf("Error preparing statement (INSERT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("SQL query prepared (INSERT)\n");

			//en el primer bind_int se mete el cod_V, en la posición '1' de la fila
			result = sqlite3_bind_int(stmt, 1, cod_V);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			//en ese caso se mete el aeropuerto Origen en la posición '2' de la fila que añade
			result = sqlite3_bind_text(stmt, 2, aero_Orig.c_str(), aero_Orig.length(), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//aeropuerto destino
			result = sqlite3_bind_text(stmt, 3, aero_Dest.c_str(), aero_Dest.length(), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//fecha
			result = sqlite3_bind_int(stmt, 4, fecha);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//hora salida
			result = sqlite3_bind_int(stmt, 5, hora_Sal);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//hora llegada
			result = sqlite3_bind_int(stmt, 6, hora_Lleg);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//precio
			result = sqlite3_bind_float(stmt, 7, precio);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				printf("Error inserting new data into Trayecto table\n");
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (INSERT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

		printf("Prepared statement finalized (INSERT)\n");

			return SQLITE_OK;
		}

		//metodo para insertar un nuevo avion
		int insertNewPlane(int cod_A, std::string nom_compania, int asientos)
		{
			sqlite3_stmt *stmt;
			return SQLITE_OK;
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