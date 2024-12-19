#include <vector>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) 
    {
        for(int i = nums.size()-1; i >= 0; i--)
        {
            int newPos = i + k >= nums.size() ? (i+k) % nums.size() : i + k;
            std::swap( nums[newPos], nums[i]);
        }
    }
};

int main(int argc, char* argv[])
{    
    std::cout << "started " << std::endl;

    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7};

    for(auto& el : nums)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl; 

    Solution().rotate(nums, 1);

    for(auto& el : nums)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;   

    return 0;
}

