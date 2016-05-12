#include "Administrador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>//para utilizar metodos de boolean

#define MAX_LONG 15 //MAX en la cadena del nombre y apellido

void clear_if_needed(char *str);

bool LoginAdmin()
{	

	FILE *f;
	char c;

	char str[MAX_LONG];
	char frmt_str[MAX_LONG];
	char frmt_str1[MAX_LONG];
	char *str1;//para introducir el string de fichero y comparar
	int l;//para medir la longitud del string 'login' introducido por el usuario
	char *login;//login, concatenación de strings para la comparación--será de 31 caracteres como máx
	char *espacio=" ";

	str1=(char*)malloc(31*sizeof(char));//se reserva memoria por valor de 31 chars
	espacio=(char*)malloc(sizeof(char));//solo es un elemento '\0'

	printf("Introduzca su nombre: ");
	fgets(str, MAX_LONG, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str);
	//printf("%s\n",frmt_str);//hasta aquí va bien la impresión

	printf("Introduzca su clave: ");
	fgets(str, MAX_LONG, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str1);

	login=(char*)malloc((strlen(frmt_str)+strlen(frmt_str1)+1)* sizeof(char));//tamaño por valor de los dos strings + espacio

	strcpy(login, frmt_str);
	printf("1 %s\n",login);//hasta aquí va bien
	//strcat(login, espacio);//ya que los strings están separados en el fichero
	//printf("2 %s\n",login);
	strcat(login, frmt_str1);
	printf("3 %s\n", login);
	l=strlen(login);

	f=fopen("Admin.txt", "r");

	while (fgets(str1, l+1, f))
    {     
      if((strcmp(str1,login))==0){
		printf("Cuenta Aceptada.\n");
		return true;
      }
    }
	/*while((c= fgetc(f)) != EOF)
	{
		fgets(str1, l+1, f);
		if((strcmp(str1,login))==0){
			printf("Cuenta Aceptada.\n");
			return true;
		}
	}*/
	printf("\n");

	fclose(f);

	free(str1);
	free(espacio);//ya que no es un pointer, solo un elemento
	free(login);

	return false;
}

void Crearcuenta(Admin *a){

	FILE *f;
	char c;
	//abrir fichero para escritura "w"
	//se pasa el nombre del fichero a crear
	//f=fopen("Admin.txt", "w");
	f=fopen("Admin.txt", "a");
	

	char str[MAX_LONG];
	char frmt_str[MAX_LONG];
	printf("Identificate para entrar al menu. \n");
	/*NOMBRE*/
	printf("Introduzca su nombre(15carac.max): ");
	fgets(str, MAX_LONG, stdin);//el string input se regoce en str
	clear_if_needed(str);//si str sobrepasa los 15 elementos se borrarán
	sscanf(str, "%s", frmt_str);//str se pasa a frmt_str para reservar espacio

	a->nombre=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
	//reserva en memoria por loe caracteres de frmt_str +1 por el \n
	strcpy(a->nombre, frmt_str);

	/*CONTRASEÑA*/
	printf("Introduzca su clave(15carac.max): ");
	fgets(str, MAX_LONG, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str);

	a->clave=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
	strcpy(a->clave, frmt_str);

	//guardar la nueva cuenta
	fprintf(f, "\n%s %s", a->nombre, a->clave);

	//cerrar fichero
	fclose(f);

}

void ImprimirAdmins(Admin a[]){
	int i;

	printf("Actualmente existen las cuentas: \n");
	//para leer sin fichero, de las posiciones que se van rellenando en el array
	/*for(i=0; i<5; i++){
		printf("%s %s.", a[i].nombre, a[i].clave);
		printf("\n");
	}*/
	FILE *f;
	char c;

	f=fopen("Admin.txt", "r");
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
void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}