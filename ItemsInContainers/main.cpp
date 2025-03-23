#include <vector>
#include <stack>
#include <tuple>

std::vector<std::tuple<int, int, int>> getInContainers(const std::string& s)
{
    int start = -1;
    std::vector<std::tuple<int, int, int>> acc;
    int sum_ = 0; 
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '|' && start != -1)
        {
            acc.push_back(std::make_tuple(start, i, sum_));
            sum_ = 0;
            start = i;
        }
        else if(s[i] == '*' && start != -1)
        {
            sum_++;
        }
        else if(s[i] == '|' && start == -1)
        {
            start = i;
        }
    }

    return acc;
}

std::vector<int> itemsInContainers(std::string s, std::vector<int> starts, std::vector<int> ends)
{  
    std::vector<std::tuple<int, int, int>> acc = getInContainers(s);
    if(acc.empty()) return {};

    std::sort(acc.begin(), acc.end(), [](const auto& a, const auto& b){return std::get<2>(a) < std::get<2>(b);});

    for(int i = 0; i < acc.size(); i++)
        printf("start : %d, end : %d, count : %d\n", std::get<0>(acc[i]), std::get<1>(acc[i]), std::get<2>(acc[i]));

    std::vector<int> out(starts.size(), 0);
    for(int i = 0; i < starts.size(); i++)
    {
        int start = starts[i];
        int end = ends[i];
        for(int j = 0; j < acc.size(); j++)
        {
            const std::tuple<int, int, int>& el = acc[j];
            if(start <= std::get<0>(el) && end >= std::get<1>(el))
                out[i] += std::get<2>(el);
        }
    }

    return out;
}

int main()
{
    auto out = itemsInContainers("|***|**|**|", {0,2}, {4,8});

    for(int i = 0; i < out.size(); i++)
        printf("out[%d] : %d\n", i, out[i]);
}