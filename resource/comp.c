#include<stdio.h>
#include<mymath.h>

int main() {
	int a = 3, b = 2;
	printf("%d + %d = %d\n", a, b, add(a, b));
	printf("%d - %d = %d\n", a, b, sub(a, b));
	printf("%d * %d = %d\n", a, b, mul(a, b));
	printf("%d / %d = %d\n", a, b, div(a, b));
}
