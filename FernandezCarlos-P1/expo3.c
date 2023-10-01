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


/*
    Metodo de calculo:
        (suponemos x >= 0, para x < 0 se aplica la conversion mostrada en "expo2.c")
        - Definiremos n como la parte entera d x y d como su parte decimal.
        - Calcularemos exp(1) utilizando el polinomio de taylor de exp(x) con un error relativo menor o igual al deseado (que llamaremos prec) dividido por n - 1.
        - Desupes se multiplica el valor obtenido de exp(1) por si mismo n veces para obtener exp(n) (error relativo: prec * n / (n + 1))
        - Seguidamente calculamos el valor de exp(d) utilizando el plinomio de taylor de exp(x) con un error relativo de prec / (n - 1)
        - Finalmente calculamos exp(x) al multiplicar exp(n) * exp(d) (error relativo: prec)


    Este metodo es muy rapido para valores de x en [-20, 20] con una precison de hasta 1e-14 para obtener un resultado casi instantaneo.
    Para precisiones mayores con valores |x| > 10 tarda unos minutos y tiende a fallar. Por eso creo que el metodo del apartado (b) tiene unos
    resultados mejores que este, consiguiendo una mayor precision y velocidad para |x| mas grandes.

    Este metodo funciona peor para valores altos de |x| on un error relativo menor a 1e-15 por que la serie de taylor de exp(1) tarda mucho en
    converger y los terminos son muy pequeños lo que hace que el ordenador asigne nan a la variable e y haga fallar al algoritmo.
*/