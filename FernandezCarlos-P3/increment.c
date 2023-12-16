/* DEBUG */
#include <stdio.h>

double increment (int p, double q, double y, double z) {
	int i ;
	double qp ;
	
	for (i = 1, qp = q; i < p; i++) qp *= q ;

	/* DEBUG */ printf(" (%le) ", (z - y) / (qp - 1)) ;
	return (z - y) / (qp - 1) ;
}
