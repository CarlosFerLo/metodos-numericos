/* Carlos Fernándz Lorán */
#include <stdio.h>
#include <math.h>

#include "normal.h"

#define TOL 1e-8
#define OBJ 0.95

int main (void) {
	double fdf, x ;
	
	/* Leemos el valor inicial de x */
	printf("Introduce el valor inicial de x: ") ;
	scanf(" %lf", &x) ;

	/* Inicializar el valor de f/df */
	fdf = (normal(x) - OBJ) * (sqrt(2 * M_PI) * exp(x*x / 2)) ;

	while (fabs(fdf) > TOL) {
		x -= fdf ; 
		fdf = (normal(x) - OBJ) * (sqrt(2 * M_PI) * exp(x*x / 2)) ;
	}

	/* Mostrar el valor obtenido y el error */
	printf("Valor obtenido de x: %le\nDiferencia: %le\n", x, fabs(normal(x) - OBJ)) ;

	return 0 ;
}
