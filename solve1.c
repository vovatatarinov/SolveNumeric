#include <stdio.h>
#include <math.h>

int main() {
    printf("Input n> ");
    int n;
    scanf("%d", &n);
    double eps;
    printf("Input epsilon> ");
    scanf("%lf", &eps);
    /* TODO:
     * 1) We have x = 0
     * 2) We can start from x = 1
     * 3) Use dx = 1 for start
     */
    double a = 0;
    double b = 1;
    double dx = 1;
    int k = 0;
    while (k < n) {
        double fa = tan(a) - a;
	double fb = tan(b) - b;
	double m = a+b;
	m /= 2;
	double fm = tan(m) - m;
	printf("LOOK IN %lf\n", m);
	if (fa * fb > 0) {
            //a += dx;
	    b += dx;
	    continue;
        }
	if (fabs(fa) < eps) {
            dx = 1;
	    printf("\nSolve found by f(a)! x = %lf\n%lf", a, fa);
	    a = b;
	    b = a + dx;
	    ++k;
	    continue;
	}
	if (fabs(fb) < eps) {
            dx = 1;
	    printf("\nSolve found by f(b)! x = %lf\n%lf", b,fb);
	    a = b;
	    b = a + dx;
	    ++k;
	    continue;
	}
	int i = 0;
        while (fabs(fm) > eps) {
            if (fb * fm < 0) {
                a = m;
                m = a + b;
		m /= 2;
                fa = tan(a) - a;
		fm = tan(m) - m;
            }
	    else if (fm * fa < 0) {
                b = m;
		m = a + b;
		m /= 2;
		fb = tan(b) - b;
		fm = tan(m) - m; 
	    }
	    if (fabs(m/(M_PI/2) -(int) m/(M_PI/2)) < eps)
	    	break;
	    ++i;
            printf("Looking in %lf\n", m);
            
	}
	dx = 1;
	if (fabs(fm) < eps)
	    printf("\nSolve found! x = %lf\n%lf", m, fm);
	a = b;
	b = a + dx;
	if (fabs(fm) < eps)
	    ++k;
    }
    printf("\n");
    return 0;
}
