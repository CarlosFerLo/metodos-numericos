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
