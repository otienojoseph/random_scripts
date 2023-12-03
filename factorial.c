#include <stdio.h>
#include <gmp.h>

mpz_t factorial(int num)
{
	mpz_t result;

	// n! = n * (n - 1)!
	if (num <= 1)
		return (1);

	result = num * factorial(num - 1);
	return result;
}

int main()
{
	mpz_t result;

	result = factorial(100);
	char *result_str = mpz_get_str(NULL, 10, result);
	printf("Result is %s \n", result_str);
	
	return (0);
}
