/*
nth root algorithm

input a `base`, `n`, then:
  1. init a x0
  2. compute x1 = 1/n * ( (n-1)*x0 + base/( (x0)^(n-1) ) )
  3. loop step 2, and check for |x1 - x0| < 1e-6

more detail to see https://en.wikipedia.org/wiki/Nth_root_algorithm
*/

#include <stdio.h>
#include <math.h>

/*
get the `Δx`
	( A / (x^(n-1)) - x) / n
*/
#define dx(base, n, x) (                   \
  ((base) / pow((x), (n) - 1) - (x)) / (n) \
)                                          \

double nthroot(double base, int n)
{
	// init a x0
	double x0 = base / 2;
	double x1 = x0 + dx(base, n, x0);
	while (fabs(x1 - x0) >= 1e-6) {
		x0 = x1;
		x1 = x0 + dx(base, n, x0);
	}
	return x0;
}

int main(int argc, char const *argv[])
{
	double val = nthroot(3, 2);
	printf("%lf\n", val);
	return 0;
}
