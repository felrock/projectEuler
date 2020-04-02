#include <iostream>

long collatz(long n)
{
  if(n%2==0)
  {
    return n/2L;
  }
  else
  {
    // since 3*n+1 is always even skip one step
    return (n*3L + 1L)/2;
  }
}

int main(int argc, char** argv)
{

  // keep memory of numbers seen to skip
  // uneccesary computation
  bool memo[1000000];
  for(int i=0; i < 1000000; i++)
  {
    memo[i] = false;
  }

  long longest_chain_number = 0, next_number;
  int max_count = 0, current_count;

  // starting from the largest number because it
  // minimized revisits
  for(long i=1000000L; i > 1; i--)
  {
    if(!memo[i])
    {
      current_count = 1;
      next_number = i;

      while(next_number != 1L)
      {
        if(next_number <= 1000000L)
        {
          memo[next_number] = true;
        }
        next_number = collatz(next_number);
        current_count++;
      }

      // swap out larger numbers
      if(current_count>max_count)
      {
        longest_chain_number = i;
        max_count = current_count;
      }
    }
  }

  std::cout << longest_chain_number<< std::endl;

  return 0;
}
