/* Carlos Fernández Lorán */
#include <math.h>

double gauss(double** a, double* x, double* b, int n, double tol) {
	int i, j, k ;
	double aux, det ;

	det =  1.0 ;

	/* Reduccion Gaussiana */
	for (k = 0; k < n; k++) {
		/* Pivotaje */
		j = k ;
		for (i = k+1; i < n; i++) {
			if (fabs(a[i][k]) > fabs(a[j][k])) {
				j = i ;
			}
		}

		if (k < j) {
			for (i = k; i < n; i++) {
				aux = a[k][i] ;
				a[k][i] = a[j][i] ;
				a[j][i] = aux ;
			}
			aux = b[k] ;
			b[k] = b[j] ;
			b[j] = aux ;
			det *= -1 ;
		}
		
		/* Comprobar si a es singular */
		if (fabs(a[k][k]) < tol) {
			return 0 ;
		}

		/* Actualizar el valor de det */
		det *= a[k][k] ;

		/* Eliminar elementos de la columa k por debajo de la fila k */
		for (i = k+1; i < n; i++) {
			aux = a[i][k] / a[k][k] ;
			a[i][k] = 0 ;
			for (j = k+1; j < n; j++) {
				a[i][j] -= a[k][j] * aux ;
			} 
			b[i] -= b[k] * aux ;
		} 
	}
	
	/* Substitucion hacia atras */
	x[n-1] = b[n-1] / a[n-1][n-1] ;

	for (i = n-2; i >= 0; i--) {
		aux = 0.0 ;
		for (j = i+1; j < n; j++) aux += a[i][j] * x[j] ;
		x[i] = (b[i] - aux) / a[i][i] ;	
	}

	return det ; 
}
