double increment (int p, double q, double y, double z) {
	int i ;
	double qp ;
	
	for (i = 0, qp = 1; i < p; i++) qp *= q ;

	 return (z - y) / (qp - 1) ;
}
