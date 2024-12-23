#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        
        if(*std::max_element(nums.begin(), nums.end()) >= target)
            return 1;

        for(int ws = 1; ws < nums.size() ; ws++)
        {
            for(int i = 0; i < nums.size();i++)
            {
                int tot = std::accumulate(nums.begin()+i, nums.begin()+i+ws, 0);
                if(tot >= target)
                    return ws;
            }
        }

        return 0;
    }
};

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5}; int t = 11;
    
    int res = Solution().minSubArrayLen(t, vec);

    std::cout << res << std::endl;
}