#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
	char *nombre;
	char *apellido;
	char *dni;
	char *email;
	char *ciudad;
} Client;

void CrearcuentaC(Client *b);

void ImprimirClients(Client b[]);

#endif