#include <iostream>

/*

the prime factors of 13195 are 5, 7, 13 and 29.

what is the largest prime factor of the number 600851475143 ?


*/
bool isprime(long a);

int main(int argc, char** argv)
{
	long long number = 600851475143l;
	long biggest_prime_factor, possible_prime_factor = 3l;
	if (number % 2l == 0)
	{
		number /= 2l;
	}

	while (number > possible_prime_factor)
	{
		if (isprime(possible_prime_factor) && number % possible_prime_factor == 0) {
			possible_prime_factor = possible_prime_factor;
			number /= possible_prime_factor;
		}
		possible_prime_factor +=2;
	}
	std::cout << number << std::endl;
	return 0;
}

/*
evaluate if inparameter is a prime
for it to work a >= 1
*/

bool isprime(long a)
{
	if (a == 1 || a == 2)
	{
		return true;
	}
	if (a % 2 == 0)
	{
		return false;
	}
	for (long i = 3; i < std::sqrt(a); i += 2)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}
