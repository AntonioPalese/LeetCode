#include <vector>
#include <string>
#include <iostream>

class Solution {
    public:
        std::vector<std::string> summaryRanges(std::vector<int>& nums) {
            std::vector<std::string> out_;

            if (nums.empty())
                return out_;

            int start, end = 0;
            start = nums[0];
            end = start;
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] == end+1)
                {
                    end=nums[i];
                    if (i == nums.size() - 1)
                        out_.push_back(std::to_string(start) + "->" + std::to_string(end));
                }
                else
                {
                    if (start != end)
                        out_.push_back(std::to_string(start) + "->" + std::to_string(end));
                    else
                        out_.push_back(std::to_string(start));

                    start = nums[i];
                    end = start;
                }     
            }

            if(end == start)
                out_.push_back(std::to_string(start));

            return out_;            
        }
    };

int main()
{
    //std::vector<int> nums{ 0, 1, 2, 4, 5, 7, 10, 11, 54, 55, 98};
    std::vector<int> nums{ };
    std::vector<std::string> r = Solution().summaryRanges( nums );

    for(const auto& val : r)
    {
        std::cout << val << std::endl;
    }
}