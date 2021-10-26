#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parseNames(std::string str)
{
  std::vector<std::string> names;
  std::string temp;
  for (const auto& chr : str)
  {
    if (chr == ',')
    {
      names.push_back(temp);
      temp = "";
      continue;
    }
    temp += chr;
  }
  names.push_back(temp);
  return names;
}

int main(int argc, char** argv)
{
  std::ifstream file(argv[1]);
  std::string temp;

  std::getline(file, temp);
  // clear single line of quotes
  temp.erase(std::remove(temp.begin(), temp.end(), '"'), temp.end());
  // split string to each name
  std::vector<std::string> names = parseNames(temp);
  // sort vector
  std::sort(names.begin(), names.end());
  // calc each name score
  long sum=0;
  for (int i=0; i < names.size(); ++i)
  {
    int sum_chars = 0;
    for (const auto& chr : names[i])
    {
      sum_chars += chr - 'A' + 1;
    }
    sum += sum_chars * (i+1);
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
