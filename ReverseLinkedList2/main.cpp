#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* o_head = head;
        ListNode* beg = nullptr;
        std::vector<ListNode*> nodes;
        for(int i = 1; head != nullptr; i++)
        {
            
            if(i >= left && i <= right)
                nodes.push_back(head);
            else
                beg = head;
            
            if(i >= right)
            {
                ListNode* end = nodes.back()->next;
                for(size_t j = nodes.size() - 1; j > 0; j--)                
                    nodes[j]->next = nodes[j-1];
                
                if(beg)
                    beg->next = nodes.back();

                nodes[0]->next = end;

                if(!beg)
                    return nodes.back();
                else
                    return o_head;
            }
            
            head = head->next;
        }

        return o_head;
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
    std::vector<int> nodes{1, 2, 3, 4, 5};
    std::vector<ListNode*> acc(nodes.size(), nullptr);
    for(int i = nodes.size() - 1 ; i >= 0; i--)
    {   
        ListNode* ll = i == nodes.size()-1 ? new ListNode(nodes[i]) : new ListNode(nodes[i], acc[i+1]);
        acc[i] = ll;
    }

    print(acc.front());
    ListNode* ret = Solution().reverseBetween(acc.front(), 2, 4);
    print(ret);

    return 0;
}