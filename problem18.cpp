#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> getValues(std::string line)
{
  char number[2];
  std::vector<int> ret;
  int i=0, val;
  for(auto ch: line)
  {
    if(ch == ' ')
    {
      val = std::stoi(std::string(number));
      ret.push_back(val);
      i = 0;
    }
    else
    {
      number[i++] = ch;
    }
  }

  val = std::stoi(std::string(number));
  ret.push_back(val);

  return ret;
}

int main(int argc, char** argv)
{
  std::fstream file("problem18.txt");
  std::string line;
  std::vector<std::vector<int>> triangle;
  int width = 1;

  while(std::getline(file, line))
  {
    triangle.push_back(getValues(line));
  }
  return 0;
}
