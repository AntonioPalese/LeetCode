#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> map;
        for(const auto& c : magazine)
        {
            map[c]++;
        }
        for(const auto& c : ransomNote)
        {
            if(map[c] == 0)            
                return false;            
            else if(map[c] > 0)            
                map[c]--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << (s.canConstruct("aa", "aab") ? "true" : "false") << std::endl;
    return 0;
}