/* Carlos Fernández Lorán */
double increment (int p, double q, double y, double z) {
	int i ;
	double qp ;
	
	for (i = 1, qp = q; i < p; i++) qp *= q ;

	return (z - y) / (qp - 1) ;
}
