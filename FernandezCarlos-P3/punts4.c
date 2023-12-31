/* Carlos Fernández Lorán */
#include <stdio.h>
#include <math.h>

void punts (double *x, double *f, int n) {
	int i ;
	double a, b ;

	/* Leer intervalo de estudio */
	printf("Introduzca el intervalo a estudiar: ") ;
	scanf(" %le %le", &a, &b) ;

	/* Calcular xi y fi */
	for (i = 0; i <= n; i++) {
		x[i] = a + i * (b - a) / n ;
		f[i] = 1 / (1 + 25 * x[i]*x[i]) ; 
	}
	

	return ;
}
