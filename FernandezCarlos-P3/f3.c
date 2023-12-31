/* Carlos Fernández Lorán */
#include <math.h>

double f (double x) {
    int signo ;

    if (x < 0) signo = -1 ;
    else signo = 1 ;

    return signo * x*x*x ;
}

double df (double x) {
    int signo ;

    if (x < 0) signo = -1 ;
    else signo = 1 ;

    return signo * 3 * x*x ;
}

double ddf (double x) {
    if (x > 0) return 6 * x ;
    else return - 6 * x ;
}