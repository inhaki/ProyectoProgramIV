#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FuncProyec/Cliente.h"
#include "FuncProyec/Administrador.h"

<<<<<<< HEAD
=======
>>>>>>> origin/master

#define MAX_CUENTAS 5 //número máximo de cuentas administrador
#define MAX_CLIENTE 10 //número máximo de cuentas cliente

void clear() {//para quitar de la entrada de caracteres el \n
	while(getchar() != '\n');
}

int main(){

	char menu;//menu ppal
	char menuc;//menu cliente
	char menua;//menu admin
	cout << "Bienvenido a la web de AirPacMaze." << endl

	do{
		cout << "- 1 para cliente. "<< endl
		cout <<"- 2 para administrador " << endl 
		cout << "- (s) para SALIR "<< endl
		cout << "Marca aqui: "
		
		scanf("%c", &menu);

		clear();

		switch(menu){
			case '1': printf("Estas dentro del menu cliente.");
					  Client client[MAX_CLIENTE];//estructura de la clase Administrador.h
					  int d=0;//para indicar que posicion se rellena
						do{
							printf("Pulsa. \n1 para registrarse como usuario. \n2 para \n3 para \nr para REGRESAR \nMarca aqui: ");
							scanf("%c", &menuc);

							clear();
							switch(menuc){

								case '1': CrearcuentaC(&client [d]);
									d++;
									break;
								case '2': 
									break;
								case '3':
									break;
								case 'r': printf("Has solicitado volver al inicio. \n");
									break;
								default: printf("No es un caracter valido, vuelve a marcar. \n");
							
							}
						}while(menuc!='r');
				break;
			case '2':	
						if(LoginAdmin()==true){//hay que corregirlo, ponerlo a true
							//corregir la concatenacion de strings, que coja los valores adecuados y no punteros
							printf("Estas dentro del menu administrador.");
							Admin admin[MAX_CUENTAS];//estructura de la clase Administrador.h
							int i=0;//para indicar que posicion se rellena
							do{
								printf("Pulsa. \n1 para crear una cuenta de administrador.\n2 para ver las cuentas del sistema.\n3 para \nr para REGRESAR \nMarca aqui: ");
								scanf("%c", &menua);

								clear();
								switch(menua){

									case '1': Crearcuenta(&admin [i]);
										i++;
										break;
									case '2': ImprimirAdmins(admin);
										break;
									case '3': ImprimirClients(client);
										break;
									case 'r': printf("Has solicitado volver al inicio. \n");
										break;
									default: printf("No es un caracter valido, vuelve a marcar. \n");

								}	
							}while(menua!='r');
						}
						else{
							printf("Usuario o clave desconocidos. \n");
						}
				break;
			case 's': printf("Ha decidido salir, se cierra la aplicacion.");
				break;
			default: printf("No es un caracter valido, vuelve a marcar. \n");

		}
	}while(menu!='s');

	return 0;
}