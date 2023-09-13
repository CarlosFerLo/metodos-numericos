/* Carlos Fernández Lorán */
#include <stdio.h>
#include <math.h>

#define PREC 1e-15

/*

ATENCIONC

En clase no se ha dado aun la diferencia entre error real y teorico asi que de momento la tabla incluira las siguientes columnas:

	x : valor de x en el que se evalua
	exp(x) : valor "real" de la exponencial en x
	prediccion: valor predicho mediante el metodo iterativo
	error absoluto: error absoluto de la prediccion
	error relativo: error relativo de la prediccion

Esto se rectificara cuando se explique como diferenciar y calcular dichos errores.

*/

int main (void) {
	int i ;
	double pred, term, x, errorAbs ;

	for (x = -25; x <= 25; x++) {		
		for (i = 1, term = 1, pred = 1; fabs(term) > PREC; i++) {
			term *= x / i ;
			pred += term ;
		}

		errorAbs = fabs(exp(x) - pred) ;
		printf("%12.5e %12.5e %12.5e %12.5e %12.5e\n", x, exp(x), pred, errorAbs, errorAbs/exp(x)) ;
	}

	return 0;
}