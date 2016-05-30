#ifndef CLIENTE_H
#define CLIENTE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *nombre;
	char *apellido;
	char *dni;
	char *email;
	char *ciudad;
} Client;

void CrearcuentaC(Client *b);

void ImprimirClients(Client b[]);

#ifdef __cplusplus
}
#endif

#endif