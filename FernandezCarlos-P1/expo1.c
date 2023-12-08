/* Carlos Fernández Lorán */
#include <stdio.h>
#include <math.h>

#define PREC 1e-15

int main (void) {
	int i ;
	double pred, term, x, errorAbs, errorTeorico ;

	for (x = -25; x <= 25; x++) {
		for (i = 1, term = 1, pred = 1; fabs(term) > PREC; i++) {
			term *= x / i ;
			pred += term ;
		}

		errorAbs = fabs(exp(x) - pred) ;
        errorTeorico = x > 0 ? fabs(exp(x) * term) : fabs(term) ;
		printf("%12.5e %12.5e %12.5e %12.5e %12.5e\n", x, errorTeorico, errorTeorico / exp(x), errorAbs, errorAbs/exp(x)) ;
	}

	return 0;
}
