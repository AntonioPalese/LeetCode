
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        const size_t R = matrix.size();
        const size_t C = matrix.front().size();

        int RS = 0;
        int CS = 0;
        int i = 0;
        for(int r = RS; r < R; r++)
        {
            for(int c = CS; c < C; c++)
            {
                if(i == 0) matrix[RS][c];
                if(i == 1) matrix[r][C-1];
                if(i == 2) matrix[R-1][C-1-c];
                if(i == 3) matrix[R-1-r][CS];
            }
            CS++;
            if(r == R-1) RS++;
            if(i == 3) i = 0; else i++;
        }

        return {};
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

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

    Solution().spiralOrder(matrix);   

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

