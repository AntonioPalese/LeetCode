#include <vector>
#include <iostream>

// class Solution {
// public:
//     std::vector<int> twoSum(std::vector<int>& numbers, int target) {
//         int left = 0; int right = numbers.size()-1;

//         while(left < right)
//         {
//             if(numbers[left]+numbers[right] == target)
//                 break;
            
//             if(numbers[left]+numbers[right] < target )
//                 left++;
//             else
//                 right--;
//         }

//         return {left+1, right+1};
//     }
// };

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int j = 0;
        int i = 1;  
        size_t size = numbers.size();
        while(i < size)
        {
            if(numbers[i]+numbers[j] == target)
                break; 

            if(numbers[i]+numbers[j] < target)
                i++;
            else
            {
                j++;
                i = j+1;
            }

            if(numbers[size-1]+numbers[j] < target)
            {
                j++;
                i = j+1;
            }         
        } 

        return {j+1, i+1};              
    }
};


int main()
{
    //std::vector<int> height = {2, 7, 11, 15}; 
    //std::vector<int> height = {2, 3, 4};
    //std::vector<int> height = {-1, 0};
    //std::vector<int> height = {1, 3, 7, 9, 15};
    //std::vector<int> height = {5, 25, 75};
    std::vector<int> height = {-10,-8,-2,1,2,5,6};
    
    std::vector res = Solution().twoSum(height, 0);

    if(!res.empty())
    {
        std::cout << "res : " << res[0] << ", " << res[1] << std::endl;
    }
    else
        std::cout << "empty" << std::endl;



    return 0;
}