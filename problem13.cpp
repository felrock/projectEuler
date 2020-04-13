#include <gmp.h>
#include <fstream>
#include <iostream>
#include <string>
#include <array>

int main(int argc, char** argv)
{
  // IO stuff
  std::fstream file("problem13.txt");
  std::string line;
  mpz_t sum, cur;
  mpz_init_set_str(sum, "0", 10);
  mpz_init_set_str(cur, "0", 10);

  while(std::getline(file, line))
  {
    mpz_init_set_str(cur, line.c_str(), 10);
    mpz_add(sum, sum, cur);
  }

  // big numbers
  char *ret_str = mpz_get_str(NULL, 10, sum);
  for(int i=0; i < 10; i++)
    std::cout << ret_str[i];
  std::cout << std::endl;

  mpz_clear(sum);
  mpz_clear(cur);
  return 0;
}
