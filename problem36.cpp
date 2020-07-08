#include <iostream>
#include <string>

// pretty slow in its current state, i would like to speed it up
// using a lookup table to previous found palindromes which i think
// would speed things up. E.g 11, 111, are found, which is a subset
// of 1111 and 11111, removing one from the front and back.

bool isBinaryPalindrome(unsigned int number)
{
  // check width
  int width=0;
  int t = number;
  while(t != 0)
  {
    t>>=1;
    ++width;
  }
  int start = 1, end = 1<<(width-1);
  while(start < end)
  {
    if((start & number) == 0 && (end & number) != 0)
    {
      return false;
    }
    else if((start & number) != 0 && (end & number) == 0)
    {
      return false;
    }
    start<<=1;
    end>>=1;
  }
  return true;
}

bool isDecimalPalindrome(unsigned int number)
{
  std::string numberAsString = std::to_string(number);
  int start = 0, end = numberAsString.size()-1;
  while(start < end)
  {
    if(numberAsString[start] != numberAsString[end])
    {
      return false;
    }
    --end;
    ++start;
  }
  return true;
}

int main(int argc, char** argv)
{
  int sum = 0;
  for(int i=0; i < 100000000; ++i)
  {
    if(isBinaryPalindrome(i) && isDecimalPalindrome(i))
    {
      sum += i;
    }
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
