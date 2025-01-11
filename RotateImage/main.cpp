/*
nx = x cosT - y senT
ny = x senT + y cosT
*/

#include <vector>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix.front().size();

        auto fnF = [&R, &C](const int r, int c)->std::pair<int, int> {return {c, C-1-r};};

        int r = 0; int c = 0;
        int tmp = matrix[0][0];
        for(int totR = 0; totR < R/2; totR++)
        {
            r = totR;    
            for(int totC = totR; totC < C-1-totR; totC++)
            {
                c = totC;
                tmp = matrix[r][c]; 
                for(int i = 0; i < 4; i++)
                {
                    auto newA = fnF(r, c);
                    int tmp2 = matrix[newA.first][newA.second];
                    matrix[newA.first][newA.second] = tmp;
                    r = newA.first;
                    c = newA.second;
                    tmp = tmp2;
                }
            }
        }
        
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = { {5, 1, 9, 6, 11}, {2, 4, 8, 10, 4}, {13, 3, 6, 7, 5}, {15, 14, 12, 16, 0}, {4,34,22,2,11} };
    const size_t R = matrix.size();
    const size_t C = matrix.front().size();

    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            std::cout << matrix[r][c];
            if(c != C-1)
                std::cout << ", ";
            else
                std::cout << "\n";

        }
    }
    std::cout << "\n\n";

    Solution().rotate(matrix);

    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            std::cout << matrix[r][c];
            if(c != C-1)
                std::cout << ", ";
            else
                std::cout << "\n";

        }
    }

}