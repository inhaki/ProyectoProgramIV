#ifndef ADMIN_H
#define ADMIN_H

#include <stdbool.h>//para evitar errires con el bool

typedef struct {
	char *nombre;
	char *clave;
} Admin;

void Crearcuenta(Admin *a);

void ImprimirAdmins(Admin a[]);

bool LoginAdmin();

#endif