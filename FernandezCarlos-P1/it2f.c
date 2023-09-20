#include <stdio.h>

#define K_MAX 34

int main (void) {
    int i ;
    float x0, x1, aux ;

    /* Inicializar valores de x0 y x1 */
    x0 = 11. / 2 ;
    x1 = 61. / 11 ;

    printf("%3.d %12.5e\n", 0, x0);
    printf("%3.d %12.5e\n", 1, x1);
    
    /* Iterar hasta K_MAX */
    for (i = 2; i <= K_MAX; i++) {
        aux = 111 - (1130 - 3000 / x0) / x1 ;
        x0 = x1 ;
        x1 = aux ;
        printf("%3.d %12.5e\n", i, x1) ;
    }

    return 0 ;
}