#include <iostream>
#include <vector>
#include <string>

#define SPIRAL_SIZE 1001

int main(int argc, char** argv)
{
   int steps = 2;
   int number = 1;
   int sum= 1;

   for (int i=0; i < SPIRAL_SIZE/2; ++i)
   {
      for (int j=0; j < 4; ++j)
      {
         number += steps;
         sum += number;
      }
      steps += 2;
   }
   std::cout << "Sum of spiral diagonal: " << sum << std::endl;

   return 0;
}