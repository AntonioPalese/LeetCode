#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 3) {
            return nums.size();
        }

        int j = 3;

        for (int i = 3; i < nums.size(); ++i) {
            if (nums[i] != nums[j - 3]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};

int main()
{
    Solution s;
    std::vector<int> inputs = {1, 1, 1, 2, 2, 2, 2, 3, 3};
    
    int res = s.removeDuplicates(inputs);

    for(auto& el : inputs){
        std::cout << el << " ";
    }

    std::cout << std::endl;

    std::cout << "res : " << res << std::endl;
}