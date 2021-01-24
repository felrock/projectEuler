#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
  std::fstream file("problem67.txt");
  std::string line;
  std::vector<std::vector<int>> triangle;
  int width = 1;

  // read triangle from file
  while(std::getline(file, line))
  {
    triangle.push_back(getValues(line));
  }

  // iterate from bottom up, sum the largest paths
  for(int i=triangle.size()-1; i > 0; i--)
  {
    for(int j=0; j < triangle[i].size(); j++)
    {
      triangle[i-1][j] += std::max(triangle[i][j+1], triangle[i][j]);
    }
  }
  // top is the maximum path sum
  std::cout << triangle[0][0] << std::endl;
  return 0;
}
