#ifndef CLIENTE_H
#define CLIENTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>//para evitar errires con el bool

typedef struct {
	char *nombre;
	char *apellido;
	char *dni;
	char *email;
	char *ciudad;
} Client;

bool LoginClien(char* nombre, char* apellido);

void CrearcuentaC(Client *b);

bool EliminarClien();

void ImprimirClients(Client b[]);

#ifdef __cplusplus
}
#endif

#endif