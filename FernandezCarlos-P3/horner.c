double horner (double *a, double z, int n) {
	int i ;
	double p ;

	/* Initialize the p variable */
	p = a[n] ;

	/* Iteratively calculate the output */
	for (i = n - 1; i >= 0; i--) {
		p = p*x + a[i] ;
	} 

	return p ;
}
