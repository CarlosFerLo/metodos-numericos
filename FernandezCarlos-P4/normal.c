#include <math.h>

#define TOL 1e-8
#define F0 0.5

#define POS 1
#define NEG 0

double normal (double x) {
	int j, m, signo ;
	double R ;

	/* Tomar x como positica y guardar su signo en la variable signo */
	if (x < 0) {
		x *= -1 ;
		signo = NEG ;
	} else {
		signo = POS ;
	}
	
	/* Calcular la integral de 0 a x */
	/* 	Calcular el valor de m que hace que R sea menor a TOL */
	m = 1 ;
	R = (x*x*x) / (6 * m*m * exp(3/2)) ;
	
	while (R > TOL) {
		m += 1 ;
		R *= ((m+1)*(m+1)) / (m*m) ;
	}

	/* Calcular la integral mediante el metodo de trapecios con ese valor d m */
	R = 0.5 + 0.5 * exp(-(x*x)/2) ;

	for (j = 1; j < m; j++) R += exp(-(j*x/m) * (j*x/m) / 2) ;

	R *= x/m ;

	/* Calcular el valor de f(x) apartir de T */
	R /= sqrt(2 * M_PI) ;
	R += F0 ;

	return (signo == POS) ? R : 1 - R ;
}
