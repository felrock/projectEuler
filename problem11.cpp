#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::array<int, 20> getGridLine(const std::string line)
{
  std::array<int, 20> ar_line;
  std::stringstream ss(line);
  std::string token;
  int i=0;

  while(std::getline(ss, token, ','))
  {
    ar_line[i++] = std::stoi(token);
  }
  ar_line[19] = std::stoi(token);

  return ar_line;
}

int main(int argc, char** argv)
{

  const int dirs[][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,-1},{-1,1},{-1,-1},{1,1}};

  std::array<std::array<int, 20>, 20> grid;
  std::ifstream file("problem11.txt");
  std::string line;
  int i=0;


  if(file.is_open())
  {
    while(std::getline(file, line))
    {
      grid[i++] = getGridLine(line);
    }
  }

  int max=0;
  for(int y=0; y < 20; y++)
  {
    for(int x=0; x < 20; x++)
    {
      for(auto d : dirs)
      {
        int p=1, d0=d[0], d1=d[1];
        for(i=0; i < 4; i++)
        {
          if(y+(d0*i) < 20 && y+(d0*i) >= 0 && x+(d1*i) < 20 && x+(d1*i) >= 0)
          {
            p*=grid[y+(d0*i)][x+(d1*i)];
          }
          else
          {
            // we don't need to care about the value of p here since
            // it will always be smaller than max
            break;
          }
        }
        if(p > max)
          max = p;
      }
    }
  }
  std::cout << max << std::endl;
  return 0;
}
