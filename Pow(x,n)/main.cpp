#include <algorithm>
#include <math.h>
#include <numeric>
#include <iostream>

class Solution {
    public:
        double myPow(double x, int n) {

            unsigned long exp = (unsigned long)n;
            if(n < 0)
                exp = -(unsigned long)n;

            if( x == 1.0)
                return 1.0;
            else if(x == -1.0)            
                return exp % 2 == 0 ? 1.0 : -1.0;            
            
            if (n == INT32_MIN)
                return 0.0;

            double t_x = std::abs(x);

            double acc = 1.0;           
            
            if (exp % 2 == 0)
            {
                for(unsigned long i = 0; i < exp / 2; i++)
                {
                    acc*=(t_x*t_x);
                }
            }
            else
            {
                for(unsigned long i = 0; i < (exp-1) / 2; i++)
                {
                    acc*=(t_x*t_x);
                }
                acc*= t_x;
            }
            
            if(x < 0.0)
                if( std::abs(n) % 2 == 0)
                    acc = acc;
                else
                    acc = -acc; 
            

            if (n > 0)
                return acc;
            else
                return 1/acc;
        }
    };

int main()
{
    std::cout << Solution().myPow(2.10, 3) << std::endl;
}