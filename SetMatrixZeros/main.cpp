#include <vector>
#include <iostream>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) 
    {
        int R = matrix.size();
        int C = matrix.front().size();
        std::vector<bool> cols_to_zero(C, false);

        auto fill = [&matrix, &R,&C](int r, int c, int val)
        {
            for(int i = 0; i < r; i++)
            {
                if(matrix[i][c] != val)
                    matrix[i][c] = val;
            }
        };

        for(int r = 0; r < R; r++)
        {
            bool active = false;
            for(int c = 0; c < C; c++)
            {
                if(matrix[r][c] == 0)
                {
                    std::fill(matrix[r].begin(), matrix[r].begin()+c, 0);
                    fill(r, c, 0);
                    active = true;
                    cols_to_zero[c] = true;
                }
                else if((matrix[r][c] != 0 && active) || (matrix[r][c] != 0 && cols_to_zero[c]))
                {
                    matrix[r][c] = 0;
                }
            }
        }
        
    }
};

int main()
{

    std::vector<std::vector<int>> matrix = {{-5,7,2147483647,3},{0,3,6,-2147483648},{8,3,-3,-6},{-9,-9,8,0}};

    int R = matrix.size();
    int C = matrix.front().size();
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

    Solution().setZeroes(matrix);   

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