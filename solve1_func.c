#include <stdio.h>
#include <math.h>
#include <float.h>

int is_nan(double x) { return x != x; }

double f(double x) {
	return tan(x) - x;
}

double dfdx(double x) {
	return tan(x)* tan(x);
}

int isRoot(double x, double eps) {
	if (fabs(f(x)) < eps)
		return 1;
	return 0;
}

double findRoots(double a, double b, double eps, double lasta, double lastb);

double findRoots(double a, double b, double eps, double lasta, double lastb) {
	if ((lasta == a) && (lastb == b))
		return NAN;
	if (isRoot(a, eps))
		return a;
	if (isRoot(a, eps))
		return b;
	double c = a + b;
	c /= 2;
	/* Break points workaround */
	/*FRAGMENT START*/ 
	/*FRAGMENT END*/
	if (isRoot(c, eps))
		return c;
    if (f(a)*f(c) < 0)
        return findRoots(a,c,eps, a, b);
    else if (f(c)*f(b) < 0)
	    return findRoots(c,b,eps,a,b);
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
    double a = 0, b = 1;
    while (i < n) {
        double x = findRoots(a,b,eps, NAN, NAN);
        if (is_nan(x)) {

        	b += eps/dfdx(b);
        	a += eps/dfdx(a);

        	if (isinf(dfdx(a))) a += eps;
        	if (isinf(dfdx(b))) b += eps;
        	continue;
        }
        ++i;
        printf("Solution found! x = %lf\n", x);
        b += eps/dfdx(b);
        a += eps/dfdx(a);


        if (isinf(dfdx(a))) a += eps;
        if (isinf(dfdx(b))) b += eps;
    }
    return 0;    
}
