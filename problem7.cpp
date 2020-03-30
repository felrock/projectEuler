/*
problem 7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include <iostream>

bool isPrime(int n)
{
	if (n == 2)
	{
		return true;
	}
	if (n % 2 == 0)
	{
		return false;
	}

	int MAX_INT_TO_TEST = sqrt(n);
	for (int i = 3; i <= MAX_INT_TO_TEST; i+=2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv) 
{
	int counter = 0;
	int number = 2;
	int current_prime = 2;
	while (counter < 10001)
	{
		if (isPrime(number))
		{
			current_prime = number;
			counter++;
		}
		number++;
	}
	std::cout << " 10001th prime is " << current_prime << std::endl;
	return 0;
}