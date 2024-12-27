#include <vector>
#include <iostream>
#include <string>
#include <set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int right = 0, left = 0;
        std::set<char> res;
        int max = 0;
        for(;right < s.size(); right++)
        {
            while(!res.insert(s[right]).second)
            {
                res.erase(s[left]);
                left++;
            }
            max = res.size() > max ? res.size() : max;
        }
        return max;
    }
};

int main()
{
    std::string s = " ";
    
    int res = Solution().lengthOfLongestSubstring(s);

    std::cout << res << std::endl;

    return 0;
}