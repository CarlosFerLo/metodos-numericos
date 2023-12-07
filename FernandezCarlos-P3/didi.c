void didi(double *x, double *f, int n) {
	int i, j ;

	for (i = 0; i <= n; i++) {
		for (j = n; j > i; j++) {
			f[j] = (f[j] - f[j - 1]) / (x[j] - x[j - 1]) ; 
		f[j] - f[j - 1]}
	}

	return ;
} 
