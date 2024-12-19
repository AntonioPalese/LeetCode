#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

class Solution {
public:

    std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        int left = 0; int right = numbers.size()-1;

        while(left < right)
        {
            if(numbers[left]+numbers[right] == target)
                break;
            
            if(numbers[left]+numbers[right] < target )
                left++;
            else
                right--;
        }

        return {numbers[left], numbers[right]};
    }
    
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::set<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            std::vector<int> tmp = twoSum(std::vector<int>(nums.begin()+i, nums.end()), -nums[i]);
            if(!tmp.empty())
            {
                tmp.push_back(nums[i]);
                std::sort(tmp.begin(), tmp.end());
                res.insert(tmp);
                // if(res.insert(tmp).second)
                //     i = 1; left = 0; right = nums.size() - 1;

                //std::cout << left << ", " << i << ", " << right << std::endl;
            }

            // if(nums[i] + nums[left] + nums[right] < 0)
            //     left++;
            // else
            //     right--;
        }

        return std::vector<std::vector<int>>(res.begin(), res.end());
    }
};

int main()
{
    std::vector<int> height = {3,0,-2,-1,1,2};

    // -2, -1, 0, 1, 2, 3
    
    std::vector res = Solution().threeSum(height);

    for(const auto& el : res)
    {
        std::cout << "[" <<el[0] << ", " << el[1] << ", " << el[2] << "]" << std::endl;
    }

    return 0;
}