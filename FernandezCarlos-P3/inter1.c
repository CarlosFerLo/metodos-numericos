/* Carlos Fernández Lorán */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gauss.h"
#include "punts.h"
#include "horner.h"

#define TOL 1e-6

int main (void) {
	int i, j, n ;
	double det, *auxp, *x, *f, *a, **M ;
	
	/* Leer valor de n (numero de puntos) */
	printf("Introduce el numero de puntos: ") ;
	scanf(" %d", &n) ;
	n -= 1 ;

	if (n <= 0) {
		printf("Valor de n no es valido.\n") ;
		return 1 ;
	}

	/* Asignar memoria para x, f */
	x = (double *) malloc((n + 1) * sizeof(double)) ;
	if (x == NULL) {
		printf("ERROR al asignar memoria para x.\n") ;
		return 1 ;
	}

	f = (double *) malloc((n + 1) * sizeof(double)) ;
	if (f == NULL) {
		printf("ERROR al asignar memoria para f.\n") ;
		return 1 ;
	}

	/* Leer los puntos del fichero utilizando la funcion punts */
	punts(x, f, n) ;

	/* Asignar memoria para la matriz M (matriz del sistema) */
	M = (double **) malloc((n + 1) * sizeof(double *)) ;
	if (M == NULL) {
		printf("ERROR al asignar memoria para M.\n") ;
		return 1 ;
	} 

	for (i = 0; i <= n; i++) {
		M[i] = (double *) malloc((n + 1) * sizeof(double)) ;
		if (M[i] == NULL) {
			printf("ERROR al asignar memoria para la fila %d de M.\n", i) ;
			return 1 ;
		}
	}
	
	/* Calcular de forma iterativa los coeficientes de la matriz M */
	for (i = 0; i <= n; i++) M[i][0] = 1 ;
	for (i = 0; i <= n; i++) {
		for (j = 1; j <= n; j++) M[i][j] = M[i][j-1] * x[i] ;
	}
	
	/* Asignar memoria para a (coeficientes del polinomio) */
	a = (double *) malloc((n + 1) * sizeof(double)) ;
	if (a == NULL) {
		printf("ERROR al asignar memoria para a.\n") ;
		return 1 ;
	}
	
	/* Asignar memoria para la variable auxiliar igual a f */
	auxp = (double *) malloc((n + 1) * sizeof(double)) ;
	if (auxp == NULL) {
		printf("ERROR al asignar memoria para auxp.\n") ;
	}

	/* Inicializar auxp como f */
	for (i = 0; i <= n; i++) auxp[i] = f[i] ;

	/* Utilizar gauss para resolver el sistema y encontrar a */
	det = gauss(M, a, f, n+1, TOL) ;
	
	if (fabs(det) < TOL) {
		printf("El sistema no tiene solicion.\n") ;
		goto liberar ;
	}

	/* Utilizar horner para comprobar que el polinomio es un interpolador */
	for (i = 0; i <= n; i++) {
		det = horner(a, x[i], n) ;
		if (fabs(det - auxp[i]) > TOL) {
			printf("El polinomio no es interpolador.\n") ;
			goto liberar ;
		}
	}	

	printf("El polinomio es interpolador.\n") ;

	/* Liberar memoria */
	liberar :
		free(x) ;
		free(f) ;
		free(a) ;
		free(auxp) ;
		for (i = 0; i <= n; i++) free(M[i]) ;
		free(M) ;

	return 0 ;
}
