#include "Cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

#define MAX_LONG 15 //MAX en la cadena del nombre y apellido
#define MAX_EMAIL 20 //MAX para el caracter email

void clear_if_neededc(char *str);

bool LoginClien(char* frmt_str, char* frmt_str1)
{
    
    FILE* f;
    char linea [100];
    
    char str [15];
    //char frmt_str [15];
    //char frmt_str1 [15];
    
    /*printf("Introduce nombre: ");
    fgets(str, 15, stdin);
    sscanf(str, "%s", frmt_str);*/
    char comparadorchar[15];
    
    /*printf("Introduce apellido: ");
    fgets(str, 15, stdin);
    sscanf(str, "%s", frmt_str1);*/
    char comparadorchar1[15];
    
    //abrir fichero para lectura
    f = fopen("Client.txt", "r");
    
    int control =1;
    int control1 =1;
    
    while (fgets(linea,100,f))
    {
        
        sscanf(linea,"%s",comparadorchar);
        control = strcmp(comparadorchar,frmt_str);
        fgets(linea,100,f);
        sscanf(linea,"%s",comparadorchar1);
        control1 = strcmp(comparadorchar1,frmt_str1);
        fgets(linea,100,f);
        fgets(linea,100,f);
        fgets(linea,100,f);
    
    if (control == 0) {
        
        if (control1 == 0)
            
        {
            
            printf("HA ENTRADO CORRECTAMENTE, HOLA %s %s \n", frmt_str, frmt_str1);
            return true;
        }

    }
        
    }
    
    return false;
}


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
    clear_if_neededc(str);//si str sobrepasa los 15 elementos se borrarán
    sscanf(str, "%s", frmt_str);//str se pasa a frmt_str para reservar espacio
    
    b->nombre=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
    //reserva en memoria por loe caracteres de frmt_str +1 por el \n
    strcpy(b->nombre, frmt_str);
    
    /*APELLIDO*/
    printf("Introduzca su apellido(15carac.max): ");
    fgets(str, MAX_LONG, stdin);
    clear_if_neededc(str);
    sscanf(str, "%s", frmt_str);
    
    b->apellido=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
    strcpy(b->apellido, frmt_str);
    
    /*EMAIL*/
    printf("Introduzca su email, sin el dominio(20carac.max): ");
    fgets(str, MAX_EMAIL, stdin);
    clear_if_neededc(str);
    sscanf(str, "%s", frmt_mail);
    
    b->email=(char *)malloc((strlen(frmt_mail)+1)* sizeof(char));
    strcpy(b->email, frmt_mail);
    
    /*DNI*/
    printf("Introduzca su Dni(15carac.max): ");
    fgets(str, MAX_LONG, stdin);
    clear_if_neededc(str);
    sscanf(str, "%s", frmt_str);
    
    b->dni=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
    strcpy(b->dni, frmt_str);
    
    /*CIUDAD*/
    printf("Introduzca su Ciudad(15carac.max): ");
    fgets(str, MAX_LONG, stdin);
    clear_if_neededc(str);
    sscanf(str, "%s", frmt_str);
    
    b->ciudad=(char *)malloc((strlen(frmt_str)+1)* sizeof(char));
    strcpy(b->ciudad, frmt_str);
    
    //guardar la nueva cuenta
    fprintf(f, "%s\n%s\n%s\n%s\n%s\n\n", b->nombre, b->apellido, b->email, b->dni, b->ciudad);
    
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

