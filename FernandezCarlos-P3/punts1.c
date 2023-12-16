/* Carlos Fernández Lorán */
#include <stdio.h>
#include <math.h>

void punts (double *x, double *f, int n) {
	int i ;
	double a, b ;

	/* Leer intervalo de estudio */
	printf("Introduzca el intervalo a estudiar: ") ;
	scanf(" %lf %lf", &a, &b) ;

	/* Calcular xi y fi */
	for (i = 0; i <= n; i++) {
		x[i] = a + i * (b - a) / n ;
		f[i] = exp(x[i]) ;
	}
	

	return ;
}
