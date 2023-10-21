/* Carlos Ferández Lorán */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_FILE_NAME_LEN 20

int main (void) {
	int n, i, j, k, na, nb ;
	double **A, *b, *x, sum, term ;
	char fname[MAX_FILE_NAME_LEN] ;
	FILE *f ;

	/* Abrir primer archivo de lectura */
	printf("Introduce el nombre del archivo que contienen A y b: ") ;
	scanf(" %s", fname) ;
	f = fopen(fname, "r") ;
	
	if (f == NULL) {
		printf("ERROR al abrir el archivo '%s'.\n", fname) ;
		return 1 ;
	}

	/* Leer dimension del sistema */
 	fscanf(f, " %d", &n) ;

	/* Reservar memoria para una matriz A de dimension nxn */
	A = (double **) malloc(n * sizeof(double *)) ;
	if (A == NULL) {
		printf("ERROR al asignar memoria para A.\n") ;
		return 1 ;
	}
	
	for (i = 0; i < n; i++) {
		*(A + i) = (double *) malloc(n * sizeof(double)) ;
		if (*(A + i) == NULL) {
			printf("ERROR al asignar memoria para A[%d].\n", i) ;
			return 1 ;
		}

		/* Asignar 0 a los elementos de A[i] */ 
		for (j = 0; j < n; j++) A[i][j] = 0 ;
	}

	/* Reservar memoria para b */
	b = (double *) malloc(n * sizeof(double)) ;
	if (b == NULL) {
		printf("ERROR al asignar memoria para b.\n") ;
		return 0 ;
	}
	for (i = 0; i < n; i++) b[i] = 0 ; /* Asignar a o los elementos de b */

	/* Leer numero de terminos diferentes a cero en A y en b */
	fscanf(f, " %d %d", &na, &nb) ;

	/* Leer y asignar los valores de dichos terminos en A */
	for (k = 0; k < na; k++) {
		fscanf(f, " %d %d", &i, &j) ;
		fscanf(f, " %lf", A[i] + j) ;
	}
	
	/* Leer y asignar los valores de dichos terminos en b */
	for (k = 0; k < nb; k++) {
		fscanf(f, " %d", &i) ;
		fscanf(f, " %lf", b + i) ;
	}

	/* Cerrar primer archivo de lectura */
	fclose(f) ;

	/* Abrir segundo archivo de lectura */
	printf("Introduce el nombre del archivo que contiene el vector x: ") ;
	scanf(" %s", fname) ;

	f = fopen(fname, "r") ;
	if (f == NULL) {	
		printf("ERROR al abrir el archivo '%s'.\n", fname) ;
		return 1 ;
	}

	/* Asignar memoria para x */
	x = (double *) malloc(n * sizeof(double)) ;
	if (x == NULL) {
		printf("ERROR al asignar memoria para x.\n") ;
		return 1 ;
	}

	/* Leer el vector x */
	for (i = 0; i < n; i++) fscanf(f, " %lf", x + i) ;

	/* Cerrar segundo archivo de lectura */
	fclose(f) ;

	/* Calcular suma termino a termino */
	sum = 0.0 ;
	for (i = 0; i < n; i++) {
		term = -b[i] ;
		for (j = 0; j < n; j++) {
			term += A[i][j] * x[j] ;
		}

		sum += term * term ;
	}

	/* Devolver resultado */
 	printf("Resultado: %le\n", sqrt(sum));

	/* Liberar memoria */
	for (i = 0; i < n; i++) free(A[i]) ;
	free(b) ;
	free(x) ;

	return 0 ;
}
