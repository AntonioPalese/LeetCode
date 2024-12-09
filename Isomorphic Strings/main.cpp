#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if ( s.size() != t.size() )
            return false;

        std::unordered_map<char, char> data1;
        std::unordered_map<char, char> data2;
        for(int i = 0; i < s.size(); i++)
        {
            if(data1.find(s[i]) == data1.end())
                data1[s[i]] = t[i];
            else if(data1[s[i]] != t[i])
                return false;   

            if(data2.find(t[i]) == data2.end())
                data2[t[i]] = s[i];
            else if(data2[t[i]] != s[i])
                return false; 
        }
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << (s.isIsomorphic("badc", "baba") ? "true" : "false") << std::endl;
    return 0;
}