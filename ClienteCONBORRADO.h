#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h>

typedef struct {
    char *nombre;
    char *apellido;
    char *dni;
    char *email;
    char *ciudad;
} Client;

void CrearcuentaC(Client *b);

bool LoginClien();

bool EliminarClien();

void ImprimirClients(Client b[]);

#endif