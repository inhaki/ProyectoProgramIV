#include "Cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONG 15 //MAX en la cadena del nombre y apellido
#define MAX_EMAIL 20 //MAX para el caracter email

void clear_if_neededc(char *str);

void CrearcuentaC(Client *b){

	FILE *f;
	char c;
	//abrir fichero para escritura "w"
	//se pasa el nombre del fichero a crear
	//f=fopen("Client.txt", "w");
	f=fopen("Client.txt", "a");
	

	char str[MAX_LONG];
	char frmt_str[MAX_LONG];
	char frmt_mail[MAX_EMAIL];
	/*NOMBRE*/
	printf("Introduzca su nombre(15carac.max): ");
	fgets(str, MAX_LONG, stdin);//el string input se regoce en str
	clear_if_needed(str);//si str sobrepasa los 15 elementos se borrarán
	sscanf(str, "%s", frmt_str);//str se pasa a frmt_str para reservar espacio

	b->nombre=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
	//reserva en memoria por loe caracteres de frmt_str +1 por el \n
	strcpy(b->nombre, frmt_str);

	/*APELLIDO*/
	printf("Introduzca su apellido(15carac.max): ");
	fgets(str, MAX_LONG, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str);

	b->apellido=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
	strcpy(b->apellido, frmt_str);

	/*EMAIL*/
	printf("Introduzca su email(20carac.max): ");
	fgets(str, MAX_EMAIL, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_mail);

	b->email=(char *)malloc((strlen(frmt_mail)+1)* sizeof(char));
	strcpy(b->email, frmt_mail);

	/*DNI*/
	printf("Introduzca su Dni(15carac.max): ");
	fgets(str, MAX_LONG, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str);

	b->dni=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
	strcpy(b->dni, frmt_str);

	/*CIUDAD*/
	printf("Introduzca su Ciudad(15carac.max): ");
	fgets(str, MAX_LONG, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str);

	b->ciudad=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
	strcpy(b->ciudad, frmt_str);

	//guardar la nueva cuenta
	fprintf(f, "\n%s %s %s %s %s", b->nombre, b->apellido, b->email, b->dni, b->ciudad);

	//cerrar fichero
	fclose(f);

}

void ImprimirClients(Client b[]){
	int i;

	printf("Actualmente existen los registros: \n");
	//para leer sin fichero, de las posiciones que se van rellenando en el array
	/*for(i=0; i<5; i++){
		printf("%s %s.", a[i].nombre, a[i].apellido);
		printf("\n");
	}*/
	FILE *f;
	char c;

	f=fopen("Client.txt", "r");
	while((c= fgetc(f)) != EOF)
	{
		putchar(c);
	}
	printf("\n");

	fclose(f);
}

/**
	Esta funcion elimina los caracteres pendientes si es necesario
	Se usa junto con fgets para leer la entrada hasta cierta longitud
*/
void clear_if_neededc(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}

