/* Carlos Fernández Lorán */
#include <stdio.h>
#include <stdlib.h>

double derivar(double x, double h, int ordre, double (*f)(double)) {
	switch (ordre) {
		case 1 :
			return (f(x + h) - f(x - h))/(2*h) ;
		case 2 :
			return (f(x + h) - 2*f(x) +f(x + h))/(h * h) ;
		default :
			printf("ERROR: la funcion derivar solo calcula derivadas de orden 1 y 2.\n") ;
			exit(1) ;	
	}
}
