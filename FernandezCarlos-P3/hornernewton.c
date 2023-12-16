/* Carlos Fernández Lorán */
double hornernewton (double *dd, double *x, double z, int n) {
	int i ;
	double p ;

	p = dd[n] ;

	for (i = n - 1; i  >= 0; i--) {
		p = p *(z - x[i]) + dd[i] ;
	}
	
	return p ;
}
