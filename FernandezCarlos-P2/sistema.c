/* Carlos Fernández Lorán */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gauss.h"

#define MAX_FILE_NAME_LEN 20

int main (void) {
	int n, i, j, k, na, nb ;
	double **a, *x, *b, det, tol ;
	char fname[MAX_FILE_NAME_LEN] ;
	FILE *f ;

	/* Agrir archivo que contiene a y b */
	printf("Introduce el nombre del archivo que contiene a y b: ") ;
	scanf(" %s", fname) ;

	f = fopen(fname, "r") ;
	if (f == NULL) {
		printf("ERROR al abrir el archivo '%s'", fname) ;
		return 1 ;
	}

	/* Leer el valor de n */
	fscanf(f, " %d", &n) ;
	if (n <= 0) {
		printf("Valor de n no valido.\n") ;
		return 1 ;
	}

	/* Asignar memoria para a, b y x */
	a = (double **) malloc(n * sizeof(double *)) ;
	if (a == NULL) {
		printf("ERROR al asignar memoria para a.\n") ;
		return 1 ;
	}

	for (i = 0; i < n; i++) {
		*(a + i) = (double *) malloc(n * sizeof(double)) ;
		if (*(a + i) == NULL) {
			printf("ERROR al asignar memoria para a[%d].\n", i) ;
			return 1 ;
		}
		for (j = 0; j < n; j++) a[i][j] = 0 ;
	}

	b = (double *) malloc(n * sizeof(double)) ;
	if (b == NULL) {
		printf("ERROR al asignar memoria para b.\n") ;
		return 1 ;
	}
	for (i = 0; i < n; i++) b[i] = 0 ;

	x = (double *) malloc(n * sizeof(double)) ;
	if (x == NULL) {
		printf("ERROR al asignar memoria para b.\n") ;
		return 1 ;
	}

	/* Leemos valores de na y nb */
	fscanf(f, " %d %d", &na, &nb) ;

	/* Leemos los valores de los terminos diferentes de 0 en a */
	for (k = 0; k < na; k++) {
		fscanf(f, " %d %d", &i, &j) ;
		fscanf(f, " %lf", a[i] + j) ;
	}

	/* Leemos los valores de los terminos diferentes de 0 en b */
	for (k = 0; k < nb; k++) {
		fscanf(f, " %d", &i) ;
		fscanf(f, " %lf", b + i) ;
	}

	/* Cerramos archivo de lectura */
	fclose(f) ;

	/* Leemos tolerancia deseada */
	printf("Introduce la tolerancia deseada: ") ;
	scanf(" %lf", &tol) ;
	
	if (tol <= 0) {
		printf("Valor de la tolerancia no valido.\n") ;
		return 1 ;
	}
	
	/* Calculamos x y det utilizando la funcion gauss de gaus.c */
	det = gauss(a, x, b, n, tol) ;

	/* Mostrar det en pantalla */
	printf("Determinante: %le\n", det) ;	

	if (fabs(det) < tol) goto free ; /* Acabar programa si det = 0 */

	/* Abrir archivo de escritura */
	printf("Introduce el nombre del archivo de escritura: ") ;
	scanf(" %s", fname) ;

	f = fopen(fname, "w") ;
	if (f == NULL) {
		printf("ERROR al abrir el archivo '%s'.\n", fname) ;
		return 1 ;
	}
	
	/* Escribir x en el archivo de escritura */
	for (i = 0; i < n; i++) fprintf(f, " %lf", x[i]) ;
	fprintf(f, "\n") ;
	
	/* Cerrar archivo de escritura */
	fclose(f) ;

	/* Liberar memoria */
	free:
		for (i = 0; i < n; i++) free(a[i]) ;
		free(a) ;
		free(b) ;
		free(x) ;

	return 0 ;
}
