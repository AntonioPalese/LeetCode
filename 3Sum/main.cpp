#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

class Solution {
public:
    
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int left = i+1;
            int right = nums.size()-1;

            while(left < right)
            {
                if(nums[left] + nums[right] == -nums[i])
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                }

                if(nums[left] + nums[right] < -nums[i] )
                    left++;
                else
                    right--;
            }
        }

        return res;
    }
};

int main()
{
    std::vector<int> height = {3,0,-2,-1,1,1};

    // -2, -1, 0, 1, 1, 3
    
    std::vector res = Solution().threeSum(height);

    for(const auto& el : res)
    {
        std::cout << "[" <<el[0] << ", " << el[1] << ", " << el[2] << "]" << std::endl;
    }

    return 0;
}