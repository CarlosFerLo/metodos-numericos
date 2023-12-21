#include <math.h>

#define TOL 1e-8

double normal (double x) {
	int sign, m, i ;
	double R, T ;

	/* Calcular solo el caso x > 0 */
	if (x < 0) {
		sign = -1 ;
		x *= -1 ;	
	} else sign = 1 ;

	/* Calcular valor de h */
	m = 1 ;
	R = (x*x*x * exp(3/2)) / 6 ;
	
	while (R > TOL) {
		m += 1 ;
		R *= (m - 1) / m ;
	}

	/* Calcular T(h) */
	T = 0.25 + 0.5 * exp(- x*x / 2) ;
	
	for (i = 1; i < m; i++) T += exp(- (i*x/m)*(i*x/m) / 2) ;

	/* Devolver f(x) o 1 - f(-x) en funcion del signo de x */
	if (sign == -1) return 1 - T ;
	else return T ;
}
