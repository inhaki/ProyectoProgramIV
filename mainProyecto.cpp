#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "Cliente/Cliente.h"
#include "Administrador/Administrador.h"
#include "bbdd.cpp"
#include "Vuelo/Vuelo.h"

using namespace std;


//Para crear el Main de cpp  --> g++ MainProyecto.cpp Administrador.o Cliente.o -o Main
// los .o ya están creados

//para ejecutar con la BBDD
//g++ mainProyecto.cpp bbdd.cpp Administrador.o Cliente.o sqlite3/sqlite3.o Vuelo/Vuelo.cpp -o mainProyecto

#define MAX_CUENTAS 5 //número máximo de cuentas administrador
#define MAX_CLIENTE 10 //número máximo de cuentas cliente

void clear_if_needed(char *str);

void clear() {//para quitar de la entrada de caracteres el \n
	while(getchar() != '\n'); // no se si esto sigue siendo lo mismo ya que eliminamos \n
}

int main(){

	char menu;//menu ppal
	char menuc;//menu cliente
	char menua;//menu admin
	Trayecto t;//instanciamos objetos de las clases vuelo para su posterior
	Avion a;//así podemos llamar a métodos de la bbdd desde dentro de las clases .cpp

	//para la interacción con la bbdd
	DBConnector dbConnector("ProyectoBBDD.s3db");

	int result;
	Client client[MAX_CLIENTE];//estructura de la clase Administrador.h lo declaramos aquí para usarlo dentro de ambos swtiches
	char nombre [15];//login cliente
    char apellido [15];
    char str [15];
	cout << "Bienvenido a la web de AirPacMaze." << endl;

	do{
		cout << "- 1 para cliente. "<< endl;
		cout <<"- 2 para administrador " << endl;
		cout << "- (s) para SALIR "<< endl;
		cout << "Marca aqui: " ;

		cin >> menu; // Esto no se como ponerlo

		cout << endl;

		clear();

		switch(menu){
			case '1': {cout << "Estas dentro del menu cliente." << endl;
					 
					  int d=0;//para indicar que posicion se rellena
					  string origen;//para búsqueda de aeropuertos según parámetros
					  string destino;
					  int cod_VueloC, cod_C;
					  int Cuenta;
					  string claseAsiento;
					  char reserva;

						do{
							cout << "Pulsa. "<< endl;
							cout << "1 para registrarse como usuario. " << endl;
							cout << "2 para ver los itinerarios de vuelo disponibles." << endl;
							cout << "3 para reservar un vuelo segun el origen y destino deseados"<<endl;
							cout << "4 para ver los vuelos reservados" << endl;
							cout << "r para REGRESAR " << endl;
							cout << "Marca aqui: "; 

							cin >> menuc;

							cout << endl;

							clear();
							switch(menuc){

								case '1': CrearcuentaC(&client [d]);
									d++;
									break;
								case '2': result = dbConnector.showAllFlights();
										if (result != SQLITE_OK) {
											printf("Error getting all planes\n");
											return result;
										}
									break;
								case '3':
										printf("Introduce nombre: ");
										fgets(str, 15, stdin);
										clear_if_needed(str);
										sscanf(str, "%s", nombre);
										printf("Introduce apellido: ");
									    fgets(str, 15, stdin);
									    clear_if_needed(str);
									    sscanf(str, "%s", apellido);
										if(LoginClien(nombre, apellido)==true){
											cout<<"Introduzca el aeropuerto desde el que desea partir: ";
											cin>>origen;
											cout<<"Introduzca su destino: ";
											cin>>destino;

											result=dbConnector.showAllFlightsByAirPort(origen, destino);
											if (result != SQLITE_OK) {
												printf("Error getting all planes\n");
												return result;
											}
											 //comprbación existe cliente
											cout<<"Desea reservar algun vuelo? S/N: ";
											cin>>reserva;
											if(reserva=='S'){
												cout<<"Introduzca el codigo del vuelo que quiere reservar: ";
												cin>>cod_VueloC;
												cout<<"Indique los 4 ultimos numeros de su DNI: ";
												cin>>cod_C;
												cout<<"Escriba en que clase le gustaria viajar: Bussiness/Turista/Prefrente: ";
												cin>>claseAsiento;
												cout<<"Por ultimo facilitenos su cuenta bancaria: ";
												cin>>Cuenta;
												  
												result=dbConnector.insertNewClientBooking(cod_C, nombre, apellido, cod_VueloC, claseAsiento, Cuenta);
												if (result != SQLITE_OK) {
													printf("Error inserting new data\n");
													return result;
												}
											}
											else{
												cout<<"Vuelva a repetir el proceso si quiere comprar algun vuelo"<<endl;
											}
										}
										else{
											cout<<"Su cuenta cliente no esta registrada."<<endl;
										} //no existe el cliente, no puede reservar vuelos									
									break;
								case '4':
										cout<<"Introduzca su codigo cliente(los 4 ultimos numeros del DNI: ";
										cin>>cod_C;
										//enseñar al cliente los vuelos que ha resrvado en su historia
										result=dbConnector.showBookingsFilteredClient(cod_C);
										if (result != SQLITE_OK) {
											printf("Error getting all bookings\n");
											return result;
										}
									break;
								case 'r': cout <<"Has solicitado volver al inicio. "<< endl;
									break;
								default: cout << "No es un caracter valido, vuelve a marcar. " << endl;
							
							}
						}while(menuc!='r');
					}
				break;
			case '2':	
						{if(LoginAdmin()==true){//hay que corregirlo, ponerlo a true
							//corregir la concatenacion de strings, que coja los valores adecuados y no punteros
							cout << "Estas dentro del menu administrador." << endl;
							Admin admin[MAX_CUENTAS];//estructura de la clase Administrador.h
							int i=0;//para indicar que posicion se rellena
							char SiNo;//para dar la opcion de añadir filas a la base de datos
							int cod_V;//para borrar un trayecto
							int cod_A;//se usa para borrar los datos de un avión
							do{
								cout << "Pulsa. " << endl;
			                    cout << "1 para crear una cuenta de administrador. "<< endl;
			                    cout << "2 para ver las cuentas del sistema. " << endl;
			                    cout << "3 para imprimir clientes" << endl;
			                    cout << "4 para ver e introducir itinerarios" << endl;
			                    cout << "5 para ver e introducir aviones" << endl;
			                    cout << "6 para borrar Trayectos" << endl;
			                    cout << "7 para borrar Aviones"<< endl;
			                    cout << "8 para ver todos los vuelos reservados por clientes"<<endl;
			                    cout << "9 para resetear la base de datos de reservas"<<endl;
			                    cout << "r para REGRESAR " << endl;
			                    cout << "Marca aqui: ";
                    
			                    cin >> menua;
			                    
			                    cout << endl;
			                    
			                    clear();
			                    switch(menua){
			                            
			                        case '1': Crearcuenta(&admin [i]);
			                            i++;
			                            break;
			                        case '2': ImprimirAdmins(admin);
			                            break;
			                        case '3': ImprimirClients(client);
			                            break;
			                        case '4': //IntroducirTrayecto (también te los enseña)
			                        	cout<<"Se muestran los itinerarios actuales: "<<endl;
			                        	result = dbConnector.showAllFlights();
										if (result != SQLITE_OK) {
											printf("Error getting all planes\n");
											return result;
										}
										cout<<"Desea anadir algun trayecto mas, S/N: ";
										cin>>SiNo;
										if(SiNo=='S'){//en ese caso se añade un nuevo trayecto
											t.crearTrayecto();
										}
										break;
			                        case '5': //Introducir y Ver vuelos
			                        		result = dbConnector.showAllPlanes();
											if (result != SQLITE_OK) {
												printf("Error getting all planes\n");
												return result;
											}
											cout<<"Desea registrar alguna aeronave mas, S/N: ";
											cin>>SiNo;
											if(SiNo=='S'){
												a.anadirAvion();
											}
			                            break;
			                        case '6': //Borrar trayectos
			                        	result = dbConnector.showAllFlights();
										if (result != SQLITE_OK) {
											printf("Error getting all flights\n");
											return result;
										}
										cout<<"Indique el cod_V del trayecto que desea borrar: ";
			                        	cin>>cod_V;
			                        	result = dbConnector.deleteFlight(cod_V);
										if (result != SQLITE_OK) {
											printf("Error deleting all flights\n");
											return result;
										}//no funciona bien, el error esta en la clase de bbdd
			                            break;
			                        case '7'://Borra aviones
			                        	result = dbConnector.showAllPlanes();
										if (result != SQLITE_OK) {
											printf("Error getting all planes\n");
											return result;
										}
										cout<<"Indique el cod_A del avion que desea eliminar: ";
			                        	cin>>cod_A;
			                        	result= dbConnector.deletePlane(cod_A);
										if (result != SQLITE_OK) {
											printf("Error deleting all planes\n");
											return result;
										}
			                        	break;
			                        case '8':
			                        	result = dbConnector.showAllBookings();
										if (result != SQLITE_OK) {
											printf("Error getting all bookings\n");
											return result;
										}
			                        	break;
			                        case '9':
			                        	result = dbConnector.deleteAllBookings();
										if (result != SQLITE_OK) {
											printf("Error deleting bookings\n");
											return result;
										}
										else{
											cout<<"Hemos reseteado la tabla ReservasClientes de la BBDD"<<endl;
										}
			                        	break;
			                        case 'r': cout <<"Has solicitado volver al inicio." << endl;
			                            break;
			                        default: cout << "No es un caracter valido, vuelve a marcar." << endl;

								}	
							}while(menua!='r');
						}
						else{
							cout << "Usuario o clave desconocidos. " << endl;
						}
					}
				break;
			case 's': {cout << "Ha decidido salir, se cierra la aplicacion." << endl;
					}
				break;
			default: {cout << "No es un caracter valido, vuelve a marcar. " << endl;
					}

		}
	}while(menu!='s');

	return 0;
}

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}