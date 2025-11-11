/*
* Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
*
*  You should preserve the original relative order of the nodes in each of the two partitions.
* */

#include <vector>
#include <iostream>
#include <string>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        // 1, 4, 3, 2, 5, 2; x = 3
        // 1, 2, 2, 3, 4, 5;

        ListNode* left = nullptr;
        ListNode* left_head = left;
        ListNode* right = nullptr;
        ListNode* right_head = right;
        ListNode* middle = right;

        while(head){
            if(head->val <= x && middle){
                if(left){
                    left->next = head;
                }else
                    left_head = head;
                left = head;
            }else if(head->val > x){
                if(right){
                    right->next = head;
                }else
                    right_head = head;
                right = head;
            }else if(!middle){
                middle = head;
            }

            head = head->next;
        } 
        left->next = middle;
        middle->next = right_head;
        right->next = nullptr;
        return left_head;
    }
};


int main(){
    std::vector<int> vec;
    int x;
    std::string token;

    printf("Insert a list of numbers : ");
    do{
        std::cin >> token;
        if(token != "q")
            vec.push_back(std::stoi(token));
    }while(token != "q");

    printf("\nInsert 'x' value : ");
    std::cin >> x;
    printf("\n");

    for(int i : vec){
        printf("%d ", i);
    }
    printf("\n");

    ListNode*l = new ListNode(vec.front());
    ListNode* head = l;
    for(size_t i = 1; i < vec.size(); ++i){
        l->next = new ListNode(vec[i]);
        l = l->next;
    }

    ListNode* ret = Solution().partition(head, x);

    while(ret){
        printf("%d ", ret->val);
        ret = ret->next;
    }
    printf("\n");
    return 0;
}
