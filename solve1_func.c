#include <stdio.h>
#include <math.h>
#include <float.h>

int is_nan(double x) { return x != x; }

double f(double x) {
	return tan(x) - x;
}

int isRoot(double x, double eps) {
	if (fabs(f(x)) < eps)
		return 1;
	return 0;
}

double findRoots(double a, double b, double eps);

double findRoots(double a, double b, double eps) {
	if (isRoot(a, eps))
		return a;
	if (isRoot(a, eps))
		return b;
	double c = a + b;
	c /= 2;
	/* Break points workaround */
	/*FRAGMENT START*/
    double tmp = c/M_PI;
    tmp += 0.5;
    int ipart = tmp;
    if (fabs(tmp - ipart) < 0.000001)
    	return NAN;
	/*FRAGMENT END*/
	if (isRoot(c, eps))
		return c;
    if (f(a)*f(c) < 0)
        return findRoots(a,c,eps);
    else if (f(c)*f(b) < 0)
	    return findRoots(c,b,eps);
	else
		return NAN;
}

int main() {
	printf("Input n> ");
    int n;
    scanf("%d", &n);
    double eps;
    printf("Input epsilon> ");
    scanf("%lf", &eps);
    int i = 0;
    double a = -M_PI/2, b = M_PI/2;
    while (i < n) {
        double x = findRoots(a,b,eps);
        if (is_nan(x)) {
        	b += M_PI;
        	a += M_PI;
        	continue;
        }
        ++i;
        printf("Solution found! x = %lf\n", x);
	a += M_PI;
	b += M_PI;
    }
    return 0;    
}
