/* Carlos Fern√°ndez Lo√n */
#include <stdio.h>

#include "normal.h"

#define FILE_NAME_MAX_LEN 20

int main (void) {
	int j ;
	char name[FILE_NAME_MAX_LEN] ;
	FILE *f ;
	
	/* Leer el nombre del archivo de escritura */
	printf("Introduce el nombre del archivo de escritura: ") ;
	scanf("%s", name) ;

	/* Abrir el archivo de escritura */
	f = fopen(name, "w") ;
	if (f == NULL) {
		printf("ERROR al abrir el archivo '%s'.\n", name) ;
		return 1 ;
	}

	/* Imprimir tabla de valores en el archivo */
	for (j = -40; j <= 40; j++) {
		fprintf(f, "%le %le\n", j/10., normal(j/10.)) ;
	}

	/* Cerrar archivo de escritura */
	fclose(f) ;

	return 0 ;
}
