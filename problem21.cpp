#include <iostream>

int properDivisorsSum(int number)
{
  int sum = 0;
  for (int i=1; i < number; ++i)
  {
    if (number % i == 0)
    {
      sum += i;
    }
  }
  return sum;
}

bool isAmicable(int number)
{
  int sum_a = properDivisorsSum(number);
  int sum_b = properDivisorsSum(sum_a);
  return number == sum_b && sum_a != number;
}

int main(int argc, char** argv)
{
  int sum=0;
  for (int n=1; n < 10000; ++n)
  {
    if (isAmicable(n))
    {
      std::cout << n << std::endl;
      sum += n;
    }
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
