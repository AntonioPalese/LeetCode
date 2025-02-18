#include <string>
#include <unordered_map>
#include <regex>
#include <iostream>
#include <vector>

class Solution {
    public:
        bool wordPattern(std::string pattern, std::string s) {            
            
            std::vector<std::string> tokens;
            std::string current;
            for(int i = 0; i < s.length(); i++)
            {
                if (s[i] != ' ')
                    current += s[i];
                else
                {
                    tokens.push_back(current);
                    current = std::string("");
                }
            }
            if (!current.empty())
                tokens.push_back(current);

            if (pattern.length() != tokens.size())
                return false;

            std::unordered_map<char, std::string> storage1;
            std::unordered_map<std::string, char> storage2;
            for(int i = 0; i < pattern.length(); i++)
            {

                if(storage1.find(pattern[i]) == storage1.end())
                    storage1[pattern[i]] = tokens[i];
                else if(storage1.find(pattern[i])->second != tokens[i])
                {
                    return false;
                }

                if(storage2.find(tokens[i]) == storage2.end())
                    storage2[tokens[i]] = pattern[i];
                else if(storage2.find(tokens[i])->second != pattern[i])
                {
                    return false;
                }
            }

            return true;

        }
};

int main()
{
    bool res = Solution().wordPattern("abba", "dog dog dog dog");
    std::string val = res ? "true" : "false";
    std::cout << "res : " << val << std::endl;
}