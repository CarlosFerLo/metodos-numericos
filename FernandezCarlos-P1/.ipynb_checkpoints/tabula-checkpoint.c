/* Carlos Fernández Lorán */
#include <stdio.h>
#include <math.h>

int main (void) {
    double x, cos ;

    for (x = -1e-3; x <= 1e-3; x+=1e-6) {
        cos = 1 - x*x/2 ;
        
        printf("%12.5le %12.5le\n", x, (1 + 3 * cos*cos - 4 * cos) / (x*x)) ;
    }
    
    return 0 ;
}

/*
    a) El grafico de f(x) generado por gnuplot (archivo "plot1.png") contiene valores erraticos de f(x) en un entorno de x = 0. Esto se debe a 
       que la funcion no esta definida en x = 0, por tanto el dibujo no es correcto para valores cercanos a 0.

    b) El algoritmo que se utilizara para calcular f(x) con un error menor a 1e-6 es el siguiente:
        - Se sustituira cos x por su Polinomio de Taylor de grado 2: 1 - x*x/2 
        - Podemos ver como el error de f(x) en este caso no es otro que |6*(cos x) - 4|/(x*x) * |(sin x) * x*x*x| / 4! 
                                                                        |--- <= 2 * 1e-6 ---|   |------ <= 1e-9 -----|
        - Para |x| <= 1e-3 el error absoluto de f(x) esta fitado por 2 * 1e-6 * 1e-9 <= 1e-6 lo que implica que este algoritmo tiene la precision deseada.

    c) La funcion f(x) no esta definida en x = 0, aunque esta puede extenderse de forma continua si fijamos f(0) = -1.
       En el apartado (a), se puede ver como el calculo directo de f(x) lleva a gnuplot a dar valores erroneos de f(x) en un entorno de x = 0 
       dado que el error en x puede llevar a x a valores muy proximos a cero para los cuales el error fruto de las operaciones se dispara.

       En el caso de grafico generado por los datos obtenidos al ejecutar este programa (se encuentran en "func.dad"), se puede ver como se reduce
       el radio con valores erraticos a un entorno muy cercano al cero, donde esta funcion se evalua como 0 pero unicamente por la aproximacion 
       utilizada. Pero fuera de este entorno se consigue una aproximacion fiel a f(x), mejor que la obtenida con gnuplot.
*/