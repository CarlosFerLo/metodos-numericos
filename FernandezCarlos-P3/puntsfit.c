/* Carlos Fernández Lorán */
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME_MAX_LEN 20

void punts (double *x, double *f, int n) {
	int i ;
	char name[FILE_NAME_MAX_LEN] ;
	FILE *file ;

	printf("Introduce el nombre del archivo de lectura: ") ;
 	scanf("%s", name) ;

	file = fopen(name, "r") ;
	if (file == NULL) {
		printf("ERROR al abrir el archivo '%s'\n", name) ;
		exit(1) ;
	}
	
	for (i = 0; i <= n; i++) {
		fscanf(file, " %le %le", x + i, f + i) ;
	}

	fclose(file) ;

	return ;	
}
