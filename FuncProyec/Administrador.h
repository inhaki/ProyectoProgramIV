#ifndef ADMIN_H
#define ADMIN_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdbool.h>//para evitar errires con el bool

typedef struct {
	char *nombre;
	char *clave;
} Admin;

void Crearcuenta(Admin *a);

void ImprimirAdmins(Admin a[]);

bool LoginAdmin();

#ifdef __cplusplus
}
#endif

#endif