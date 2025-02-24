#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head)
            return head;

        std::vector<ListNode*> nodes;

        for(int c = 0; head; /**/)
        {
            if(head->next)
            {
                if(head->val != head->next->val)
                {
                    if(c == 0)
                        nodes.push_back(head);
                    else
                        c = 0;
                }
                else
                    c++;
            }
            else if(!head->next && c == 0)
                nodes.push_back(head);

            head = head->next;
        }

        if(nodes.empty())
            return nullptr;

        for(int i = 0; i < nodes.size()-1; i++)
        {
            nodes[i]->next = nodes[i+1];
        }
        nodes.back()->next = nullptr;

        return nodes.front();
    }
};

int main()
{
    std::vector<int> nodes{1, 1};
    std::vector<ListNode*> acc(nodes.size(), nullptr);
    for(int i = nodes.size() - 1 ; i >= 0; i--)
    {   
        ListNode* ll = i == nodes.size()-1 ? new ListNode(nodes[i]) : new ListNode(nodes[i], acc[i+1]);
        acc[i] = ll;
    }

    print(acc.front());
    ListNode* ret = Solution().deleteDuplicates(acc.front());
    print(ret);

    return 0;
}