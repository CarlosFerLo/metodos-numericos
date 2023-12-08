#include <stdio.h>
#include <stdlib.h>

#include "derivar.h"
#include "f.h"
#include "increment.h"

int main (void) {
	int k, ordre ;
	double prec, q, x, h ;

	/* Lectura de los datos */
	printf("Introduce la precision deseada para la derivada: ") ;
	scanf(" %lf", &prec) ;

	if (prec <= 0) {
		printf("Valor de la precision no puede ser negativo o 0.\n") ;
		return 1 ;
	}

	printf("Indtroduce el factor de disminucion del paso: ") ;
	scanf(" %lf", &q) ;

	printf("Introduce el numero maximo de etapas de extrapolación: ") ;
	scanf(" %d", &k) ;

	if (k <= 0) {
		printf("Valor de k no valido.\n") ;
		return 1 ;
	}
	
	printf("Formula de diferenciacion numérica a utilizar [1/2]: ") ;
	scanf(" %d", &ordre) ;

	if (ordre < 1 || ordre > 2) {
		printf("Valor de ordre no valido.\n") ;
		return 1 ;
	}

	printf("Introduce el punto donde se quiere calcular la derivada: ") ;
	scanf(" %lf", &x) ;

	printf("Introduce el paso inicial: ") ;
	scanf(" %lf", &h) ;

	

	return 0 ;
}
