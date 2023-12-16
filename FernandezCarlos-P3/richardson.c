/* Carlos Fernández Lorán */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "derivar.h"
#include "f.h"
#include "increment.h"

int main (void) {
	int k, ordre, i, j ;
	double prec, q, x, h, *r1, *r2, *auxp ;

	/* Lectura de los datos */
	printf("Introduce la precision deseada para la derivada: ") ;
	scanf(" %le", &prec) ;

	if (prec <= 0) {
		printf("Valor de la precision no puede ser negativo o 0.\n") ;
		return 1 ;
	}

	printf("Indtroduce el factor de disminucion del paso: ") ;
	scanf(" %le", &q) ;

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
	scanf(" %le", &x) ;

	printf("Introduce el paso inicial: ") ;
	scanf(" %le", &h) ;

	/* Asignar memoria para los vectores r1 y r2 */
	r1 = (double *) malloc(k * sizeof(double)) ;
	if (r1 == NULL) {
		printf("ERROR al asignar memoria para r1.\n") ;
		return 1 ;
	}

	r2 = (double *) malloc(k * sizeof(double)) ;
	if (r2 == NULL) {
		printf("ERROR al asignar memoria para r2.\n") ;
		return 1 ;
	}

	/* Calcular F1(h) */
	r1[0] = derivar(x, h, ordre, f) ;

	/* Iterar hasta satisfacer condicion de parada */
	for (i = 1; i < k; i++) {
		/* Actualizar valor de h */
		h /= q ;

		/* Calcular F1 */
		r2[0] = derivar(x, h, ordre, f) ;

		/* Comprobar si cumple condicion de parada */
		if (fabs(r1[0] - r2[0]) < prec) {
			printf("El valor de la derivada en x = %le es %le\n", x, r2[0]) ;
			printf("El error real es: %le\n", (ordre == 1) ? fabs(df(x) - r2[0]) : fabs(ddf(x) - r2[0])) ;
			goto liberar ;
		}

		/* Calcular Fj+1 para 1 < j < i-1 */
		for (j = 1; j < i; j++) {
			/* Calcular Fj+1 */
			r2[j] = r2[j-1] + increment(2*(j-1), q, r1[j-1], r2[j-1]) ;

			/* Comprobar si se cumple la condicion de parada */
			if (fabs(r1[j] - r2[j]) < prec) {
				printf("El valor de la derivada en x = %le es %le\n", x, r2[j]) ;
				printf("El error real es: %le\n", (ordre == 1) ? fabs(df(x) - r2[j]) : fabs(ddf(x) - r2[j])) ;
				goto liberar ;
			}
		}

		/* Calcular Fi */
		r2[i] = r2[i-1] + increment(2*(i-1), q, r1[i-1], r2[i-1]) ;

		/* Intercanviar vectorees r1 y r2 */
		auxp = r1 ;
		r1 = r2 ;
		r2 = auxp ;
	}

	/* Devolver resultado obtenido en caso de no obtener la precision deseada*/
	printf("ERROR: No se ha obtenido la precision deseada.\n") ; ;

	/* Liberar memoria */
	liberar :
		free(r1) ;
		free(r2) ;

	return 0 ;
}
