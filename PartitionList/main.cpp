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

        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* ltail = left;
        ListNode* rtail = right;
        
        while(head){
            if(head->val < x){
                ltail->next = head;
                ltail = head;
            }else{
                rtail->next = head;
                rtail = head;
            }
            head = head->next;
        }

        ltail->next = right->next;
        rtail->next = nullptr;
        return left->next;

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
