#include <vector>
#include <iostream>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {

        int right = 0, left = 0, current_sum = 0;
        int res = INT_MAX;
        while(right < nums.size())
        {
            current_sum += nums[right];

            while(current_sum >= target)
            {
                res = right - left + 1 < res ? right - left + 1 : res;
                current_sum -= nums[left];
                left++;
            }

            right++;
        }

        return res != INT_MAX ? res : 0;
    }
};

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5}; int t = 11;
    
    int res = Solution().minSubArrayLen(t, vec);

    std::cout << res << std::endl;

    return 0;
}