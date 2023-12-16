/* Carlos Fernández Lorán */
#include <math.h>

double f (double x) {
    return x*x*x * log(fabs(x)) ;
}

double df (double x) {
    return x*x * (1 + 3 * log(fabs(x))) ;
}