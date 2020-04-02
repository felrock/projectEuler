#include <iostream>
#include <vector>

int main(int argc, char** argv)
{

  /*
   * What I found out writing this down on paper is that the only
   * values I need to keep track of is all paths to the positions
   * on the right(down works too since it's mirrored).
   */

  const int SIDES = 10;
  std::vector<long long> points;
  points.push_back(1L);
  points.push_back(3L);
  points.push_back(6L);

  for(int x=3; x <= 20; x++)
  {
    std::vector<long long> next_points;
    long long rest = 0;
    for(auto p: points)
    {
      next_points.push_back(p+rest);
      rest +=p;
    }
    next_points.push_back(rest*2);
    points = next_points;
  }

  std::cout << points[points.size()-1] << std::endl;
  return 0;
}
