#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "FuncProyec/Cliente.h"
#include "FuncProyec/Administrador.h"
#include "bbdd.cpp"

using namespace std;


//Para crear el Main de cpp  --> g++ MainProyecto.cpp Administrador.o Cliente.o -o Main
// los .o ya están creados

//para ejecutar con la BBDD
//g++ mainProyecto.cpp bbdd.cpp Administrador.o Cliente.o sqlite3/sqlite3.o -o mainProyecto

#define MAX_CUENTAS 5 //número máximo de cuentas administrador
#define MAX_CLIENTE 10 //número máximo de cuentas cliente

void clear() {//para quitar de la entrada de caracteres el \n
	while(getchar() != '\n'); // no se si esto sigue siendo lo mismo ya que eliminamos \n
}

int main(){

	char menu;//menu ppal
	char menuc;//menu cliente
	char menua;//menu admin

	//para la interacción con la bbdd
	DBConnector dbConnector("ProyectoBBDD.s3db");

	int result;

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
					  Client client[MAX_CLIENTE];//estructura de la clase Administrador.h
					  int d=0;//para indicar que posicion se rellena
						do{
							cout << "Pulsa. "<< endl;
							cout << "1 para registrarse como usuario. " << endl;
							cout << "2 para ver los itinerarios de vuelo disponibles." << endl;
							cout << "3 para ver los vuelos reservados" << endl;
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
								case '3': int cod_C;
										cout<<"Introduzca su codigo cliente: ";
										cin>>cod_C;
										cout<<endl;
										cout<<"Codigo: "<<cod_C<<endl;
										//enseñar al cliente los vuelos que ha resrvado en su historia

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
							do{
								cout << "Pulsa. " << endl;
			                    cout << "1 para crear una cuenta de administrador. "<< endl;
			                    cout << "2 para ver las cuentas del sistema. " << endl;
			                    cout << "3 para imprimir clientes" << endl;
			                    cout << "4 para ver e introducir itinerarios" << endl;
			                    cout << "5 para ver e introducir aviones" << endl;
			                    cout << "6 para borrar Trayectos" << endl;
			                    cout << "7 para borrar Aviones"<< endl;
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
			                        case '3': //ImprimirClients(client);
			                            break;
			                        case '4': //IntroducirTrayecto (también te los enseña)
			                        		result = dbConnector.showAllFlights();
										if (result != SQLITE_OK) {
											printf("Error getting all planes\n");
											return result;
										}
			                            break;
			                        case '5': //Introducir y Ver vuelos
			                        		result = dbConnector.showAllPlanes();
											if (result != SQLITE_OK) {
												printf("Error getting all planes\n");
												return result;
											}
			                            break;
			                        case '6': //Borrar trayectos
			                            break;
			                        case '7'://Borra aviones
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