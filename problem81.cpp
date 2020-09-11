#include <fstream>
#include <iostream>
#include <vector>
#include <string>

/*
 * Problem description: given a grid of numbers find the sum of the smallest path from top
 * left corner to right down corner. It's only possible to walk right and down.
 *
 *
 * My solution uses a merge technique starting at the end and propagate the smallest sum
 * towards the start. Basically creating outlines of sub-squares within the larger square
 * and solving them separately. This solution updates in-place so it also solves for start
 * to be located anywhere in the grid.
 *
 *      Here is a small visual example, on a 4x4 square, with two steps
 *
 *                      step = 0                 step = 1                step = 2
 *
 *                  x---x---x---x---x        x---x---x---x---x       x---x---x---x---x 
 *                  |   |   |   |   |        |   |   |   |   |       |   |   |   |   |
 *                  x---x---x---x---x        x---x---x---x---x       x---x---x---x---x 
 *                  |   |   |   |   |        |   |   |   |   |       |   |   |   |   |
 *                  x---x---1---4---3  -->   x---x---1---4---3  -->  x---x---5-<-4-<-4 
 *                  |   |   |   |   |        |   |   |   |   |       |   |   ^   ^   ^
 *                  x---x---1---0---2        x---x---1---3-<-3       x---x---4-<-3---1 
 *                  |   |   |   |   |        |   |   |   ^   ^       |   |   ^   |   |
 *                  x---x---2---3---1        x---x---2---4-<-1       x---x---4-<-2---1 
 *
 */

using namespace std;

vector<int> parseLine(string line, char delimiter)
{
    string temp;
    vector<int> result;
    for(const auto& ch : line)
    {
        if(ch == delimiter)
        {
            result.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += ch;
        }
    }

    // add what left when loop exits
    result.push_back(stoi(temp));

    return result;
}

int main(int argc, char** argv)
{
    vector<vector<int>> grid;

    // read grid from file
    string file_name = "input_pe81.txt"; 
    fstream fs(file_name);
    for(string line; getline(fs, line);)
    {
        grid.push_back(parseLine(line, ','));    
    }

    // walk the diagonal
    int start_x, start_y;
    int steps = 1;

    for(int i=grid.size()-2; i >= 0; --i)
    {
        // propagate best results to the diagonal of the grid
        int walk_start = i + steps;
        int temp_steps = steps;
        
        while(temp_steps > 0)
        {


           // walk Y-side
           if(temp_steps == steps)
           {
               // at the edge of grid
               grid[i+steps][i] += grid[i+steps][i+1];
           }
           else
           {
                if(grid[i+temp_steps+1][i] < grid[i+temp_steps][i+1])
                {
                   // chosen down
                   grid[i+temp_steps][i] += grid[i+temp_steps+1][i];
                }
                else
                {
                   // chosen right
                   grid[i+temp_steps][i] += grid[i+temp_steps][i+1];
                }
           }

           // walk x-side
           if(temp_steps == steps)
           {
               // at the edge of grid
               grid[i][i+steps] += grid[i+1][i+steps];
           }
           else
           {
                if(grid[i][i+temp_steps+1] < grid[i+1][i+temp_steps])
                {
                   // chosen right
                   grid[i][i+temp_steps] += grid[i][i+temp_steps+1];
                }
                else
                {
                   // chosen down
                   grid[i][i+temp_steps] += grid[i+1][i+temp_steps];
                }
           }
           --temp_steps;
        }

        // final selection for diagonal
        if(grid[i][i+1] > grid[i+1][i])
        {
           grid[i][i] += grid[i+1][i]; 
        }
        else
        {
           grid[i][i] += grid[i][i+1]; 
        }
        ++steps; 
    }

    cout << grid[0][0] << endl;
    return EXIT_SUCCESS;
}
