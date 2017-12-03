#include <iostream>
#include <string>

/*

a palindromic number reads the same both ways. the largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

find the largest palindrome made from the product of two 3-digit numbers.

*/

bool ispanlindrome(std::string a);
bool three_number_products(int num);

int main(int argc, char** argv)
{
	int max_num = 999 * 999;
	bool palindrome_found = false;
	while (!palindrome_found)
	{
		std::string s = std::to_string(max_num);
		if (ispanlindrome(s))
		{
			if (three_number_products(max_num)) {
				palindrome_found = true;
			}
		}
		max_num--;
	}
	std::cout << max_num+1 << std::endl;
	return 0;
}

bool ispanlindrome(std::string a)
{
	int last_index = a.size() - 1;
	for (int i = 0; i < a.size()/2; i++) {
		if (a[i] != a[last_index - i]) {
			return false;
		}
	}
	return true;
}

bool three_number_products(int num)
{
	for (int i = 100; i < 999; i++)
	{
		for (int j = 100; j < 999; j++)
		{
			if (j*i == num) 
			{
				return true;
			}
		}
	}
	return false;
}
