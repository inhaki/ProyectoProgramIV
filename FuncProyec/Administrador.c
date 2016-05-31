#include "Administrador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>//para utilizar metodos de boolean

#define MAX_LONG 15 //MAX en la cadena del nombre y apellido

void clear_if_needed(char *str);

bool LoginAdmin()
{
    
    FILE* f;
    int contrasena =0;
    char linea [100];
    //float contraseña;
    int counter =1;
    int retorno =0;
    
    char str [15];
    char frmt_str [15];
    int  comparador =0;
    
    printf("Introduce nombre: ");
    fgets(str, 15, stdin);
    sscanf(str, "%s", frmt_str);
    
    printf("Introduce constrasena: ");
    fgets(str, 15, stdin);
    sscanf(str, "%d", &comparador);;
    char comparadorchar[15];
    
    //abrir fichero para lectura
    f = fopen("Admin.txt", "r");
    
    int control =1;
                    
    while (fgets(linea,100,f))
    {
        
        
        sscanf(linea,"%s",comparadorchar);
        control = strcmp(comparadorchar,frmt_str);
        
        if (control ==0)
            
        {
            
            fgets(linea,100,f);
            sscanf(linea,"%d",&contrasena);
            
            if (comparador == contrasena)
                
            {
                
                printf("\nNOMBRE Y CONTRASENA CORRECTA");
                printf("\n\nHOLA %s ;)\n\n", frmt_str);
                retorno =1;
                
            }
            
            control =1;

            
        }
        
        counter++;
        
    }
    
    if (retorno != 1)
        
    {
        
        printf("\n\nEL NOMBRE O LA CONTRASENA NO SON CORRECTAS :P\n\n");
        return false;
        
    }
   
    return true;
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