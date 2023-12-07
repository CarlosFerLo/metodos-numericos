double hornernewton (double *dd, double *x, double z, double n) {
	int i ;
	double p ;

	p = dd[0] ;

	for (i = 1; i <= n; i++) {
		p = p * x[i] + dd[i] ;
	}
	
	return p ;
}
