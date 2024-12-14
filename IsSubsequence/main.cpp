/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
 (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

    Input: s = "abc", t = "ahbgdc"
    Output: true

Example 2:

    Input: s = "axc", t = "ahbgdc"
    Output: false
*/

#include <string>
#include <iostream>

class Solution {
public:
    bool isSubsequence( std::string s, std::string t) {

        if (s.size() > t.size()) return false;
        if (s.size() == t.size() && t.compare(s) != 0) return false;

        int k = 0;
        for(int i = 0; i < t.size(); i++)
        {
            if(k<s.size() && t[i] == s[k])
                k++;
        }
        return k == s.size();
    }
};

int main()
{
    std::cout << (Solution().isSubsequence("axc", "ahbgdc") ? "true" : "false") << std::endl;
}
