/* Carlos Fernández Lorán */

#include <stdio.h>
#include <math.h>

#define K_MAX 34

int main (void) {
    int i ;
    double x0, x1, aux, err_x0, err_x1, aux_err ;

    /* Inicializar valores de x0 y x1 */
    x0 = 11. / 2 ;
    x1 = 61. / 11 ;

    /* Inicializar los valores de err_x0 y err_x1 */
    err_x0 = 0.0 ;
    err_x1 = 61/11 * 2.22 * 1e-16 ;

    printf("%3.d %12.5le %12.5le\n", 0, x0, err_x0) ;
    printf("%3.d %12.5le %12.5le\n", 1, x1, err_x1) ;
    
    /* Iterar hasta K_MAX */
    for (i = 2; i <= K_MAX; i++) {
        aux = 111 - 1130 / x0 + 3000/(x0*x1) ;
        aux_err = fabs((1130 - 3000/x1)/(x0*x0)) * err_x0 + fabs(3000/(x1*x0*x0)) * err_x1 ;
        x0 = x1 ;
        x1 = aux ;
        err_x0 = err_x1 ;
        err_x1 = aux_err ;
        printf("%3.d %12.5le %12.5le\n", i, x1, err_x1) ;
    }

    return 0 ;
}