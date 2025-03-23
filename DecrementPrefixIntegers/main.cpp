#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

int getMinimumOperations(const std::vector<int>& nums) {
    long long cur_sum = 0;
    long long count = 0;

    for (int i = nums.size() - 1; i >= 0; --i) {
        if(nums[i] + cur_sum > 0)
        {
            count += nums[i] + cur_sum;
            cur_sum -= nums[i] + cur_sum;
        }
        else if(nums[i] + cur_sum < 0)
        {
            count += abs(nums[i] + cur_sum);
            cur_sum += abs(nums[i] + cur_sum);
        }

    }

    return static_cast<int>(count);
}

int main() {
    std::vector<int> arr = {3, 2, 0, 0, -1};
    std::cout << "Minimum operations: " << getMinimumOperations(arr) << std::endl;
    return 0;
}