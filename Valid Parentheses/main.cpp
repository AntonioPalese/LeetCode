#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> storage;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                storage.push(s[i]);
            else if(s[i] == ')' && !storage.empty() && storage.top() == '(')
                storage.pop();
            else if(s[i] == ']' && !storage.empty() && storage.top() == '[')
                storage.pop();
            else if(s[i] == '}' && !storage.empty() && storage.top() == '{')
                storage.pop();
            else 
                return false;                
        }

        return storage.empty();

    }
};

int main()
{
    std::string val = Solution().isValid("([{}])") ? "true" : "false";
    std::cout << val << std::endl;

    return 0;
}