#include <stack>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <numeric>
#include "LinkedList.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        ListNode* head = nullptr;
        ListNode* act_head = nullptr;

        while (c1 || c2)
        {
            ListNode* candidate = nullptr;
            if(c1 && c2)
            {
                if(c1->val < c2->val)
                {
                    candidate = c1;
                    c1 = c1->next;
                }
                else    
                {
                    candidate = c2;     
                    c2 = c2->next; 
                }         
            }
            else if(c1)
            {
                candidate = c1;
                c1 = c1->next;
            }
            else if(c2)
            {
                candidate = c2;
                c2 = c2->next; 
            }
            else
                break;

            if(!head)
            {
                head = new ListNode(candidate->val, nullptr);
                act_head = head;
            }
            else
            {
                ListNode* act = new ListNode(candidate->val, nullptr);
                act_head->next = act;
                act_head = act;
            }
        }

        return head;
        
    }
};

void print(ListNode* c)
{
    while(c != nullptr)
    {
        printf("%d ", c->val);
        c = c->next;
    }
    printf("\n");
}

int main()
{
    LinkedList ll1( { 0, 2 } );
    LinkedList ll2( { 1, 3 } );
    ListNode* ll3 = Solution().mergeTwoLists(ll1.nodes.front(), ll2.nodes.front());  
    print(ll3);

    return 0;
}