/* Carlos Fernández Lorán */
#include <math.h>

double f (double x) {
    return x*x*x * log(fabs(x)) ;
}

double df (double x) {
    return x*x * (1 + 3 * log(fabs(x))) ;
}

double ddf (double x) {
    return (x >= 0) ? 2 + 6 * log(fabs(x)) + 3 : 2 + 6 * log(fabs(x)) - 3 ;
}