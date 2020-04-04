#include <iostream>
#include <array>

/*
 * Solved using memoization. Introducing denominations one at a time
 * and updating the grid.
 */

int main(int argc, char** argv)
{
  const int MAX_PENCE = 200;
  const int MAX_DENOM = 8;
  std::array<int, MAX_DENOM> denomination = {1,2,5,10,20,50,100,200};

  std::array<int, MAX_PENCE+1> current;
  std::array<int, MAX_PENCE+1> previous;

  for(int j=0; j < MAX_PENCE+1; j++)
  {
    previous[j] = 1;
    current[j] = 1;
  }

  for(int i=1; i < MAX_DENOM; i++)
  {
    for(int j=1; j <= MAX_PENCE; j++)
    {
      int cnt = previous[j];
      int start = denomination[i];

      while(start <= j)
      {
        cnt += previous[j-start];
        start += denomination[i];
      }
      current[j] = cnt;
    }
    previous = current;
  }
  std::cout << current[MAX_PENCE] << std::endl;
  return 0;
}
