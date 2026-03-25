#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int i, unsigned long long cur, unsigned long long prev) {
	printf("%llu, ", cur);
	if (i < n) {
		return fibonacci(n, i + 1, cur + prev, cur);
	} else {
		return -1;
	}
}

int main(int argc, char *argv[])
{
	unsigned long long n = 10;

	if (argc > 1) {
		n = atoi(argv[1]);
	}

	fibonacci(n, 0, 0, 1);

	return 0;

}

