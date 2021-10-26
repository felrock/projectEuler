#include <iostream>

#define SPIRAL_SIZE 1001

int main(int argc, char** argv)
{
   int number = 1;
   int sum= 1;

   for (int i=0; i < SPIRAL_SIZE/2; ++i)
   {
      for (int j=0; j < 4; ++j)
      {
         number += (i+1)*2;
         sum += number;
      }
   }
   std::cout << "Sum of spiral diagonal: " << sum << std::endl;

   return 0;
}