#include <stdio.h>

/*
扩展欧几里得算法

求出 A 和 B 的最大公约数，并求出 X，Y 满足 AX + BY = GCD（A, B）

B = 0:
	X = 1, Y = 0

B > 0:
	GCD(A, B) = GCD(B, A mod B)
	BX' + (A mod B)Y' = GCD(B, A mod B) = GCD(A, B), A mod B = A - (A/B)xB
	BX' + (A - A/BxB)Y' = AY' + B(X' - A/B x Y') = GCD(A, B)
	=> X = Y', Y = X' - A/B x Y'
*/
int extend_gcd(int a, int b, int *x, int *y)
{
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	} else {
		int r = extend_gcd(b, a % b, y, x);
		*y -= *x * (a/b);
		return r;
	}
}

int main(void)
{
	int a = 24, b = 16;
	int x = 0, y = 0;
	int gcd = extend_gcd(a, b, &x, &y);
	printf("%d, %d, %d", gcd, x, y);
	return 0;
}
