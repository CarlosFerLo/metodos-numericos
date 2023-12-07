#include <stdio.h>
#include <math.h>

#define PI 3.141592653589

void punts (double *x, double *f, int n) {
	int i ;
	double a, b ;

	/* Leer intervalo de estudio */
	printf("Introduzca el intervalo a estudiar: ") ;
	scanf(" %lf %lf", &a, &b) ;

	/* Calcular xi y fi */
	for (i = 0; i <= n; i++) {
		x[n-i] = a + ((b - a) / 2) * (1 + cos(PI*(2*i + 1)/(2*n + 2))) ;
		f[n-i] = fabs(x[i]) ;
	}
	

	return ;
}
