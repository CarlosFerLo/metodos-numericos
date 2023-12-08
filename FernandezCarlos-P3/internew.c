#include <stdio.h>
#include <stdlib.h>

#include "didi.h"
#include "hornernewton.h"
#include "punts.h"

#define FILE_NAME_MAX_LEN 20

int main (void) {
	int n, m, i ;
	double *x, *f ;
	char name[FILE_NAME_MAX_LEN] ;
	FILE *file ;	

	/* Leer el grado del polinomio (n) */
	printf("Introduzca el grado del polinomio: ") ;
	scanf(" %d", &n) ;	

	if (n < 0) {
		printf("Valor de n no es valido.\n") ;
		return 1 ;
	}

	/* Asignar memoria para los vectores x y f */
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

	/* Utilizst la function punts para inicializar las variables x y f */
	punts(x, f, n) ;

	/* Calculara los coeficientes del polinomio utilizando la funcion didi */
	didi(x, f, n) ;

	/* Leer valor de m */
	printf("Introduzca el numero de intervalos en [%lf, %lf]: ", x[0], x[n]) ;
	scanf(" %d", &m) ;

	if (m <= 0) {
		printf("Valor de m no valido.\n") ;
		return 1 ;
	}

	/* Leer nombre del fichero de escritura */
	printf("Introduzca el nombre del archivo de escritura: ") ;
	scanf("%s", name) ;
	
	/* Abrir archivo de escritura */
	file = fopen(name, "w") ;
	
	if (file == NULL) {
		printf("ERROR al abrir el archivo '%s'.\n", name) ;
		return 1 ;
	}

	/* Evaluar p en los diferentes puntos y escribir en el archivo */
	for (i = 0; i <= m; i++) {
		fprintf(file, "%lf %lf\n", x[0] + i * (x[n] - x[0]) / m, hornernewton(f, x, x[0] + i * (x[n] - x[0]) / m, n)) ; 
	}

	/* Cerrar archivo de escritura */
	fclose(file) ;

	/* liverar memoria */
	free(x) ;
	free(f) ;

	return 0 ;
}
