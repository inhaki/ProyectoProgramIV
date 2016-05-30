#include <stdio.h>
#include "sqlite3/sqlite3.h"
#include <string.h>

//metodo para insertar un nuevo trayecto---poner precio a float??
int insertNewFlight(sqlite3 *db, int cod_V, char aero_Orig[], char aero_Dest[], int fecha, int hora_Sal, int hora_Lleg, int precio)
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
	result = sqlite3_bind_text(stmt, 2, aero_Orig, strlen(aero_Orig), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	//aeropuerto destino
	result = sqlite3_bind_text(stmt, 3, aero_Dest, strlen(aero_Dest), SQLITE_STATIC);
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
	//precio es float
	result = sqlite3_bind_int(stmt, 7, precio);
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
int insertNewPlane(sqlite3 *db, int cod_A, char nom_compania[], int asientos)
{
	sqlite3_stmt *stmt;
	///nueva tabla de aviones
	char sql[]= "insert into Avion (cod_A, nom_compania, asientos) values (?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL );
	if(result != SQLITE_OK){
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	//codigo del avion
	result = sqlite3_bind_int(stmt, 1, cod_A);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	//nombre de la compañia
	result = sqlite3_bind_text(stmt, 2, nom_compania, strlen(nom_compania), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	//numero de asientos
	result = sqlite3_bind_int(stmt, 3, asientos);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Avion table\n");
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

int showAllFlights(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "select cod_V, aero_Orig, aero_Dest, fecha, hora_Sal, hora_Lleg, precio from Trayecto";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int cod_V;
	char aero_Orig[100];
	char aero_Dest[100];
	int fecha;
	int hora_Sal;
	int hora_Lleg;
	int precio;

	printf("\n");
	printf("\n");
	printf("Showing flights:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cod_V = sqlite3_column_int(stmt, 0);//coge la columna de id es la (0) en el ejemplo
			strcpy(aero_Orig, (char *) sqlite3_column_text(stmt, 1));//esta columna es la (1)
			strcpy(aero_Dest, (char *) sqlite3_column_text(stmt, 2));
			fecha= sqlite3_column_int(stmt, 3);
			hora_Sal= sqlite3_column_int(stmt, 4);
			hora_Lleg= sqlite3_column_int(stmt, 5);
			precio= sqlite3_column_int(stmt, 6);
			printf("Cod_Vuelo: %d Origen: %s Destino: %s, Fecha: %d Hora_Salida %d y Hora_Llegada %d, precio= %d\n", cod_V, aero_Orig, aero_Dest, fecha, hora_Sal, hora_Lleg, precio);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("Prepared statement finalized (SELECT)\n");
	
	return SQLITE_OK;

}

int showAllPlanes(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "select cod_A, nom_compania, asientos from Avion";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int cod_A;
	char nom_compania[100];
	int asientos;

	printf("\n");
	printf("\n");
	printf("Showing planes:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cod_A = sqlite3_column_int(stmt, 0);//coge la columna de id es la (0) en el ejemplo
			strcpy(nom_compania, (char *) sqlite3_column_text(stmt, 1));//esta columna es la (1)
			asientos= sqlite3_column_int(stmt, 2);
			printf("Cod_Avion: %d Compania: %s Numero_Asientos %d\n", cod_A, nom_compania, asientos);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int deleteAllCountry(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from country";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}



int main() {
	sqlite3 *db;

	int result = sqlite3_open("ProyectoBBDD.s3db", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	/*result = deleteAllCountry(db);
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}*/

	/*int result = dbConnector.insertNewPlane(db, 100, "Aena", 50);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		return result;
	}
	result= dbConnector.insertNewFlight(db, 0002, "SS", "BCN", 1603, 1750, 1850, 150);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		return result;
	}*/	
	result = showAllPlanes(db);
	if (result != SQLITE_OK) {
		printf("Error getting all planes\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = showAllFlights(db);
	if (result != SQLITE_OK) {
		printf("Error getting all planes\n");
		return result;
	}

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;

	return 0;
}
