#include <stack>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <numeric>
#include "LinkedList.h"


class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        int residual = 0;
        
        ListNode* head = nullptr;
        ListNode* act_head = nullptr;

        while(c1 || c2)
        {
            int digit_sum = 0;

            if(c1)
            {
                digit_sum+= c1->val;
                c1 = c1->next;
            }
            if(c2)
            {
                digit_sum+= c2->val;
                c2 = c2->next;
            }
            
            digit_sum+=residual;

            if (digit_sum > 9)
            {
                float dl = std::floorf(digit_sum / 10.0f);
                int d  = digit_sum - dl*10;
                digit_sum = d;
                residual = (int)dl;
            }
            else
            {
                residual = 0;
            }   
            
            if(!act_head)
            {
                act_head = new ListNode(digit_sum, nullptr);
                head = act_head;
            }
            else
            {
                ListNode* actual = new ListNode(digit_sum, nullptr);
                act_head->next = actual;
                act_head = actual;
            }
        }

        while (residual > 0)
        {
            if(residual < 10)
            {
                ListNode* actual = new ListNode(residual, nullptr);
                act_head->next = actual;
                act_head = actual;
                residual = 0;
            }
            else
            {
                float dl = std::floorf(residual / 10.0f);
                int d  = residual - dl*10;    

                ListNode* actual = new ListNode(residual, nullptr);
                act_head->next = actual;
                act_head = actual;
                residual = (int)dl;
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
    LinkedList ll1( { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9  } );
    LinkedList ll2( { 1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 } );

    ListNode* ll3 = Solution().addTwoNumbers(ll1.nodes.front(), ll2.nodes.front());  
    print(ll3);

    return 0;
}