/* Carlos Fernández Lorán */
void didi(double *x, double *f, int n) {
	int i, j ;

	for (i = 1; i <= n; i++) {
		for (j = n; j >= i; j--) {
			f[j] = (f[j] - f[j - 1]) / (x[j] - x[j-i]) ; 
		}
	}

	return ;
} 
