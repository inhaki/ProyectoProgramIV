#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "FuncProyec/Cliente.h"
#include "FuncProyec/Administrador.h"

using namespace std;


//Para crear el Main de cpp  --> g++ MainProyecto.cpp Administrador.o Cliente.o -o Main
// los .o ya están creados

#define MAX_CUENTAS 5 //número máximo de cuentas administrador
#define MAX_CLIENTE 10 //número máximo de cuentas cliente

void clear() {//para quitar de la entrada de caracteres el \n
	while(getchar() != '\n'); // no se si esto sigue siendo lo mismo ya que eliminamos \n
}

int main(){

	char menu;//menu ppal
	char menuc;//menu cliente
	char menua;//menu admin

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
							cout << "2 para " << endl;
							cout << "3 para " << endl;
							cout << "r para REGRESAR " << endl;
							cout << "Marca aqui: "; 

							cin >> menuc;

							cout << endl;

							clear();
							switch(menuc){

								case '1': CrearcuentaC(&client [d]);
									d++;
									break;
								case '2': 
									break;
								case '3':
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
								cout << "3 para " << endl;
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