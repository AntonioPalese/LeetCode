#include <unordered_map>
#include <string>

std::string solution(const std::string& s, const std::string& t)
{
	std::unordered_map<int, int> ht;
	std::unordered_map<int, int> ht_founded;
	std::vector<std::pair<int, int>> candidate;
	for(int i = 0; i < t.length(); i++)
	{
		ht[t[i]]++;
	}
	
	int start = 0; int end = 0;
	int acc = 0;
	int min_size = INT_MAX;

	
	for(int i = 0; i < s.length(); i++)
	{
		if(ht.find(s[i]) != ht.end() && ht_founded.find(s[i]) == ht_founded.end() || ht_founded[s[i]] < ht[s[i]])
		{
			start = i;
			acc++;
			ht_founded[s[i]]++;
		{
		

		
		if(acc == t.length())
		{

			candidate.push_back({start, i});

			if(ht_founded.find(s[start]) == ht_founded.end() || ht_founded[s[i]] > ht[s[i]])
			{
				start++;	
			}
		}		
		end++;		
	}
	
	return candidate;
}


int main()
{
	/*
	Input: s = "ADOBECODEBANC", t = "ABC"
	Output: "BANC"
	*/
	//std::string s = "ADOBECODEBANCABA";
	//std::string t = "ABCA";
	std::string s = "aaabcbc";
	std::string t = "abc";
	std::string out = solution(s, t);
	printf("out : %s\n", out.c_str());

}
