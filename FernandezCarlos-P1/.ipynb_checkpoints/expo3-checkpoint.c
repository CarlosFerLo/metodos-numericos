/* Carlos Fernández Lorán */
#include <stdio.h>
#include <math.h>

int main (void) {
    int i, n, is_neg ;
    double prec, x, aux, e, term, pred ;

    /* Leer x */
    scanf(" %lf", &x) ;
    
    /* Leer error relativo deseado */
    scanf(" %lf", &prec) ;

    /* Comprobar si x es negativo */
    if (x < 0) {
        is_neg = -1 ;
        x *= -1 ;
    } else {
        is_neg = 1 ;
    }
    
    /* Calcular valor de e con error relativo prec/(n+1) */
    n = floor(x) ;
    for (i = 1, term = 1, e = 1; fabs(exp(1) - e) / exp(1) > prec / (n + 1); i++) {
        term /= i ;
        e += term ;
    }

    /* Calcular exp(n) */
    for (i = 0, pred = 1; i < n; i++) pred *= (is_neg == -1) ? 1/e : e; 

    /* Calcular ahora el ultimo factor de la exponencial */
    aux = x - n ;
    for (i = 1, term = 1, e = 1; fabs(exp(aux) - e) / exp(aux) > prec / (n + 1); i++) {
        term *= aux / i;
        e += term ;
    }

    pred *= (is_neg == -1) ? 1/e : e ;
    
    /* Alterar el valor de pred si x es negativa */
    if (is_neg == -1) {
        x *= -1 ;
    }

    /* Mostrar resultados */
    printf("%12.5e %12.5e %12.5e", x, exp(x) - pred, fabs(exp(x) - pred)/exp(x));
    
    return 0 ;
}
