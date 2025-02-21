#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string res;

        if (strs.empty())
            return res;

        int j = 0;
        char current;
        while(true)
        {
            current = strs[0][j];

            for(int i = 0; i < strs.size(); i++)
            {
                if (j == strs[i].length())
                    return res;

                if (current != strs[i][j])
                {
                    return res;
                }
            }
            res+=current;
            j++;
        }
    }
};

int main()
{
    std::vector<std::string> val{"s", "ss", "sss"};
    const std::string& res = Solution().longestCommonPrefix(val);
    std::cout << "res : " << res << "\n";
}