#include <array>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#define INF 99999999


using namespace std;


struct Node
{
    int index;
    int weight;
    vector<int> neighbors;
};

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

int minDistance(vector<int> dist, vector<bool> visited)
{
    int md = INF, index=0;
    for(int i=0; i < dist.size(); ++i)
    {
        if(!visited[i] && dist[i] <= md)
        {
            md = dist[i];
            index = i;
        }
    }
    return index;
}

bool allVisted(vector<bool> visited)
{
    for( auto v : visited)
    {
        if(!v)
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    vector<vector<int>> grid;

    // read input into 2d matrix
    string file_name = "problem82.txt"; 
    fstream fs(file_name);
    for(string line; getline(fs, line);)
    {
        grid.push_back(parseLine(line, ','));    
    }
    // create graph
    // There are a couple of ways to store a graph in memory, one way is to
    // store all vertexes to each node as arrays. Meaning, for 80 nodes, 
    // 80x80 arrays are used to represent it.
    //
    // Another way is to store nodes in a linked-list fashion. I will use the latter.

    vector<Node*> nodes;
    int width = grid[0].size();
    int height = grid.size();
    int node_count = width*height;

    for(int i=0; i < height; ++i)
    {
        vector<Node*> nodes_row;
        for(int j=0; j < width; ++j)
        {
           Node *temp = new Node;
           temp->index = i*height + j;
           temp->weight = grid[i][j];
           vector<int> nb;
           if(i+1 < height)
           {
                nb.push_back((i+1)*height + j);
           }
           if(i-1 >= 0)
           {
                nb.push_back((i-1)*height + j);
           }
           if(j+1 < width)
           {
                nb.push_back(i*height + (j+1));
           }
           temp->neighbors = nb;
           nodes.push_back(temp);
        }
    }
    // Run djikstras algo from all possible start positions, left side
    int best_path_dist = INF;
    vector<int> new_dist;
    vector<bool> new_visited;
    for(int i=0; i < node_count; ++i)
    {
        new_dist.push_back(INF);
        new_visited.push_back(false);
    }
    for(int s=0; s < height*width; s+=height)
    {
        
        vector<int> dist = new_dist;
        vector<bool> visited = new_visited;
        
        dist[s] = nodes[s]->weight;

        while(allVisted(visited))
        {
            
            int j = minDistance(dist, visited);
            visited[j] = true;
            for(auto k : nodes[j]->neighbors)
            {
                if(!visited[k] && dist[j] != INF && 
                   (dist[j] + nodes[k]->weight) < dist[k])
                {
                    dist[k] = dist[j] + nodes[k]->weight;
                }
            }

        }

        // check smallest dist in the on the right side
        int path_dist = INF;
        int temp_index = -1;
        for(int k=0; k < height; ++k)
        {
            if(path_dist > dist[k*height + width-1] )
            {
                path_dist = dist[k*height + width-1]; 
                temp_index = k*height + width-1;
            }
        }
        if(best_path_dist > path_dist)
        {
            best_path_dist = path_dist;
        }
    }
    cout << "Best found path distance is: " << best_path_dist << endl;
    return EXIT_SUCCESS;
}
