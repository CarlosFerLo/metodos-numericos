/* Carlos Fernández Lorán */
#include <stdio.h>
#include <math.h>

#define PREC 1e-15

int main (void) {
	int i, is_neg ;
	double pred, term, x, errorAbs, errorTeorico ;

	for (x = -25; x <= 25; x++) {
        if (x < 0) {
            x = fabs(x) ;
            is_neg = -1 ;
        } else {
            is_neg = 1 ;
        }
        
		for (i = 1, term = 1, pred = 1; fabs(term) > PREC; i++) {
			term *= x / i ;
			pred += term ;
		}
        
        if (is_neg == -1) {
                pred = 1/pred ;
                x *= -1 ;
        }

		errorAbs = fabs(exp(x) - pred) ;
        errorTeorico = x > 0 ? fabs(exp(x) * term) : fabs(term) ;
		printf("%12.5e %12.5e %12.5e %12.5e %12.5e\n", x, errorTeorico, errorTeorico / exp(x), errorAbs, errorAbs/exp(x)) ;
	}

	return 0;
}

/*
    Para calcular exp(x) unicamente si x > 0, lo que se ha hecho es utilizar el mismo algoritmo que antes para calcular exp(|x|) y en funcion de si
    x < 0 o no se invertia (1 / exp(|x|) si x < 0).

    El resultado es un menor error real para x < 0 que en el caso anterior.

*/
