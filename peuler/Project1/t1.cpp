/*
problem 1	

if we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. the sum of these multiples is 23.

find the sum of all the multiples of 3 or 5 below 1000.

- o(n) solution
*/

#include <iostream>

int main(int argc, char** argv) 
{
	int sum = 0;
	const int sum_to = 1000;
	for (int i = 1; i < sum_to; i++) 
	{
		if (i % 3 == 0) 
		{
			sum += i;
		}
		else if (i % 5 == 0)
		{
			sum += i;
		}
	}
	std::cout << sum << std::endl;
	return 0;
}