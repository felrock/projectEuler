#include <algorithm>
#include <array>
#include <iostream>

int main(int argc, char** argv)
{
    const int SIZE = 1000;
    std::array<int, SIZE> P;
    std::fill(P.begin(), P.end(), 0);
    for (int i=3; i < SIZE; ++i)
    {
        for (int j=i; i+j < SIZE; ++j)
        {
            for (int k=j; i+j+k < SIZE; ++k)
            {
                if ((i*i + j*j) == k*k)
                {
                    P[i+j+k]++;
                } 
            }
        }
    }
    std::cout << std::max_element(P.begin(), P.end())-P.begin() << std::endl;
    return 0;
}