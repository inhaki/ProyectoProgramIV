#include "sqlite3/sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class DBConnector{
	//clase de la bbdd

	private:
		sqlite3 *db = NULL;

	public:

		//metodo para insertar un nuevo trayecto---poner precio a float??
		int insertNewFlight(int cod_V, std::string aero_Orig, std::string aero_Dest, int fecha, int hora_Sal, int hora_Lleg, int precio)
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
		int insertNewPlane(int cod_A, std::string nom_compania, int asientos)
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
			result = sqlite3_bind_text(stmt, 2, nom_compania.c_str(), nom_compania.length(), SQLITE_STATIC);
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

		//método para guardar las reservas de los clientes
		int insertNewClientBooking(int cod_C, std::string NomC, std::string ApellidoC, int cod_V, std::string Clase, int Num_Tarjeta)
		{
			sqlite3_stmt *stmt;

			char sql[]= "insert into ReservaCliente (cod_C, NomC, ApellidoC, cod_V, Clase, Num_Tarjeta) values (?, ?, ?, ?, ?, ?)";
			int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL );
			if(result != SQLITE_OK){
				printf("Error preparing statement (INSERT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("SQL query prepared (INSERT)\n");

			result = sqlite3_bind_int(stmt, 1, cod_C);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			//datos del cliente
			result = sqlite3_bind_text(stmt, 2, NomC.c_str(), NomC.length(), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			result = sqlite3_bind_text(stmt, 3, ApellidoC.c_str(), ApellidoC.length(), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			
			result = sqlite3_bind_int(stmt, 4, cod_V);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//clase bussiness, preferente o turista
			result = sqlite3_bind_text(stmt, 5, Clase.c_str(), Clase.length(), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
	
			result = sqlite3_bind_int(stmt, 6, Num_Tarjeta);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			

			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				printf("Error inserting new data into ReservaCliente table\n");
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

		int deleteFlight(int cod_V){
			sqlite3_stmt *stmt;	

			printf("Cod_Vuelo que se borra: %d\n", cod_V);

			char sql[] = "delete from Trayecto where cod_V= (?)";

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			//coge como parámetros el puntero a la base de datos;
			//la sentencia; el -1, y &stmt(pasamos la direccion del puntero); y NULL
			
			if (result != SQLITE_OK) {
				printf("Error preparing statement (DELETE)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//si todo ha ido bien se notifica
			printf("SQL query prepared (DELETE)\n");

			//le decimos donde está el parámetro a borrar en la tabla Trayecto
			result = sqlite3_bind_int(stmt, 1, cod_V);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			//y se ejecuta el statement 'stmt'
			//sqlite3_step, el step ejecuta la consulta
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				printf("Error deleting data\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//terminar con el statement
			//si se produce el error se notifica y acaba la ejecución
			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (DELETE)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("Prepared statement finalized (DELETE)\n");

			return SQLITE_OK;

		}

		int deletePlane(int cod_A){
			sqlite3_stmt *stmt;	

			printf("Cod_Avion que se borra: %d\n", cod_A);

			char sql[] = "delete from Avion where cod_A= (?)";//sentencia que queremos realizar

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			//coge como parámetros el puntero a la base de datos;
			//la sentencia; el -1, y &stmt(pasamos la direccion del puntero); y NULL
			
			if (result != SQLITE_OK) {
				printf("Error preparing statement (DELETE)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//si todo ha ido bien se notifica
			printf("SQL query prepared (DELETE)\n");

			//el atributo que debe buscar se encuentra en la posicion 1 de la tabla: clave primaria
			result = sqlite3_bind_int(stmt, 1, cod_A);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			//y se ejecuta el statement 'stmt'
			//sqlite3_step, el step ejecuta la consulta
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				printf("Error deleting data\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//terminar con el statement
			//si se produce el error se notifica y acaba la ejecución
			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (DELETE)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("Prepared statement finalized (DELETE)\n");

			return SQLITE_OK;

		}

		int deleteAllBookings(){
			sqlite3_stmt *stmt;

			char sql[] = "delete from ReservaCliente";//sentencia que queremos realizar

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			//coge como parámetros el puntero a la base de datos;
			//la sentencia; el -1, y &stmt(pasamos la direccion del puntero); y NULL
			
			if (result != SQLITE_OK) {
				printf("Error preparing statement (DELETE)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//si todo ha ido bien se notifica
			printf("SQL query prepared (DELETE)\n");

			//y se ejecuta el statement 'stmt'
			//sqlite3_step, el step ejecuta la consulta
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				printf("Error deleting data\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			//terminar con el statement
			//si se produce el error se notifica y acaba la ejecución
			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (DELETE)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("Prepared statement finalized (DELETE)\n");

			return SQLITE_OK;
		}


		int showAllPlanes(){
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

		int showAllBookings(){
			sqlite3_stmt *stmt;

			char sql[] = "select cod_C, NomC, ApellidoC, Clase, cod_V, Num_Tarjeta  from ReservaCliente"; //\
			//" select fecha, aero_Orig, aero_Dest from Trayecto"; 
			//char sql1[]= "select cod_V, fecha, aero_Orig, aero_Dest from Trayecto";
			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			//result= sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL); 
			if (result != SQLITE_OK) {
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("SQL query prepared (SELECT)\n");

			int cod_C;
			int cod_V;
			char NomC[100];
			char ApellidoC[100];
			char Clase[50];
			int Num_Tarjeta;
			//char aero_Orig[100];
			//char aero_Dest[100];
			//int fecha;
	

			printf("\n");
			printf("\n");
			printf("Showing bookings:\n");
			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
					cod_C = sqlite3_column_int(stmt, 0);//coge la columna de id es la (0) en el ejemplo
					strcpy(NomC, (char *) sqlite3_column_text(stmt, 1));//esta columna es la (1)
					strcpy(ApellidoC, (char *) sqlite3_column_text(stmt, 2));
					strcpy(Clase, (char*) sqlite3_column_text(stmt, 3));
					cod_V = sqlite3_column_int(stmt, 4);
					Num_Tarjeta=sqlite3_column_int(stmt, 5);
					//strcpy(aero_Orig, (char *) sqlite3_column_text(stmt, 1));//esta columna es la (1)
					//strcpy(aero_Dest, (char *) sqlite3_column_text(stmt, 2));
					//fecha= sqlite3_column_int(stmt, 3);
					//printf("Cod_Cliente: %d Nombre: %s Apellido: %s, Clase: %s Cod_Vuelo: %d Origen: %s Destino: %s, Fecha: %d \n", cod_C, NomC, ApellidoC, Clase, cod_V, aero_Orig, aero_Dest, fecha);
					printf("Cod_Cliente: %d Nombre: %s Apellido: %s, Clase: %s Cod_Vuelo: %d y Num_Tarjeta Credito: %d\n", cod_C, NomC, ApellidoC, Clase, cod_V, Num_Tarjeta);
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

		int showBookingsFilteredClient(int cod_Cliente){

			sqlite3_stmt *stmt;

			char sql[] = "select cod_C, NomC, ApellidoC, Clase, cod_V from ReservaCliente where cod_C=(?)"; //\
		
			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("SQL query prepared (SELECT)\n");

			result = sqlite3_bind_int(stmt, 1, cod_Cliente);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			int cod_C;
			int cod_V;
			char NomC[100];
			char ApellidoC[100];
			char Clase[50];
	

			printf("\n");
			printf("\n");
			printf("Showing bookings:\n");
			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
					cod_C = sqlite3_column_int(stmt, 0);//coge la columna de id es la (0) en el ejemplo
					strcpy(NomC, (char *) sqlite3_column_text(stmt, 1));//esta columna es la (1)
					strcpy(ApellidoC, (char *) sqlite3_column_text(stmt, 2));
					strcpy(Clase, (char*) sqlite3_column_text(stmt, 3));
					cod_V = sqlite3_column_int(stmt, 4);//coge la columna de id es la (0) en el ejemplo
					printf("Cod_Cliente: %d Nombre: %s Apellido: %s, Clase: %s Cod_Vuelo: %d \n", cod_C, NomC, ApellidoC, Clase, cod_V);
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

		int showAllFlights(){
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
					printf("Cod_Vuelo: %d Origen: %s Destino: %s, Fecha: %d Hora_Salida %d y Hora_Llegada %d, precio= %d euros\n", cod_V, aero_Orig, aero_Dest, fecha, hora_Sal, hora_Lleg, precio);
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

		int showAllFlightsByAirPort(std::string Origen, std::string Destino){
			sqlite3_stmt *stmt;

			char sql[] = "select cod_V, aero_Orig, aero_Dest, fecha, hora_Sal, hora_Lleg, precio from Trayecto where aero_Orig=(?) and aero_Dest=(?)";
			
			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("SQL query prepared (SELECT)\n");

			//filtro aeropuerto origen
			result = sqlite3_bind_text(stmt, 1, Origen.c_str(), Origen.length(), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			
			//filtro aeropuerto destino
			result = sqlite3_bind_text(stmt, 2, Destino.c_str(), Destino.length(), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			int cod_V;
			char aeropuerto_Orig[100];
			char aeropuerto_Dest[100];
			int fecha;
			int hora_Sal;
			int hora_Lleg;
			int precio;

			printf("\n");
			printf("\n");
			printf("Showing flights filtered by AirPort:\n");
			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
					cod_V = sqlite3_column_int(stmt, 0);
					strcpy(aeropuerto_Orig, (char *) sqlite3_column_text(stmt, 1));//esta columna es la (1)
					strcpy(aeropuerto_Dest, (char *) sqlite3_column_text(stmt, 2));
					fecha= sqlite3_column_int(stmt, 3);
					hora_Sal= sqlite3_column_int(stmt, 4);
					hora_Lleg= sqlite3_column_int(stmt, 5);
					precio= sqlite3_column_int(stmt, 6);
					printf("Cod_Vuelo: %d Origen: %s Destino: %s, Fecha: %d Hora_Salida %d y Hora_Llegada %d, precio= %d euros\n", cod_V, aeropuerto_Orig, aeropuerto_Dest, fecha, hora_Sal, hora_Lleg, precio);
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

		//construcctor el dbFile es el parámtero que pasamos al llamar al método en el DBConnector
		DBConnector(std::string dbFile) {
			int result = sqlite3_open("ProyectoBBDD.s3db", &db);
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

/*int main(){
	//para comprobar que funciona bien
	DBConnector dbConnector("ProyectoBBDD.s3db");

	int result;

	//UNA VEZ INTRODUCIDOS LOS DATOS, NO SE PUEDEN INTRODUCIR DE NUEVO LOS MISMOS

	/*result = dbConnector.insertNewPlane(200, "GermanWings", 100);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		return result;
	}*/

	/*result= dbConnector.insertNewFlight(0003, "MAD", "BCN", 106, 1430, 1520, 130);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		return result;
	}*/

	/*result=dbConnector.insertNewClientBooking(3, "Pablo", "Vilegas", 0002, "Turista", 23498121);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		return result;
	}*/

	//LOS DELETE NO FUNCIONAN BIEN!!!
	/*result = dbConnector.deleteFlight(3);
	if (result != SQLITE_OK) {
		printf("Error deleting flight\n");
		return result;
	}*/

	/*result= dbConnector.deletePlane(0);
	if (result != SQLITE_OK) {
		printf("Error deleting plane\n");
		return result;
	}*/
	
	/*result = dbConnector.deleteAllBookings();
	if (result != SQLITE_OK) {
		printf("Error deleting bookings\n");
		return result;
	}*/
/*
	result=dbConnector.showBookingsFilteredClient(1);
	if (result != SQLITE_OK) {
		printf("Error getting all bookings\n");
		return result;
	}

	result = dbConnector.showAllPlanes();
	if (result != SQLITE_OK) {
		printf("Error getting all planes\n");
		return result;
	}

	result=dbConnector.showAllFlightsByAirPort("SS", "BCN");
	if (result != SQLITE_OK) {
		printf("Error getting all flights\n");
		return result;
	}

	result = dbConnector.showAllFlights();
	if (result != SQLITE_OK) {
		printf("Error getting all flights\n");
		return result;
	}

	result= dbConnector.showAllBookings();
	if (result != SQLITE_OK) {
		printf("Error getting all bookings\n");
		return result;
	}

	return 0;
}*/