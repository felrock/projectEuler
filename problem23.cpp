#include <iostream>

int sumOfDivisors(int number)
{
  int sum=0;
  for (int i=1; i < number; ++i)
  {
    if (number % i == 0)
    {
      sum += i;
    }
  }
  return sum;
}

bool isAbundant(int number)
{
  return number < sumOfDivisors(number);
}

int main(int argc, char** argv)
{
  bool abundant_numbers[28124];
  for (int i=1; i < 28124; ++i)
  {
    abundant_numbers[i] = isAbundant(i);
  }
  int sum=0;
  for (int i=1; i < 28124; ++i)
  {
    bool found=true;
    for (int j=1; j < i; ++j)
    {
      if(abundant_numbers[j] && abundant_numbers[i - j])
      {
        found = false;
        break;
      }
    }
    if (found)
    {
      sum += i;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
