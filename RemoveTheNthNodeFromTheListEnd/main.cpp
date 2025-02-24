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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        std::vector<ListNode*> storage;
        while(head)
        {
            storage.push_back(head);
            head = head->next;
        }

        if(storage.empty())
            return nullptr;

        int to_remove = storage.size() - n;
        
        if(to_remove == 0)
        {
            if(n == 1)
                return nullptr;
            else
                return storage[1];
        }

        storage[to_remove-1]->next = storage[to_remove]->next;
        return storage.front();        
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
    std::vector<int> nodes{1, 2, 5, 5, 5, 5};
    std::vector<ListNode*> acc(nodes.size(), nullptr);
    for(int i = nodes.size() - 1 ; i >= 0; i--)
    {   
        ListNode* ll = i == nodes.size()-1 ? new ListNode(nodes[i]) : new ListNode(nodes[i], acc[i+1]);
        acc[i] = ll;
    }

    print(acc.front());
    ListNode* ret = Solution().removeNthFromEnd(acc.front(), 1);
    print(ret);

    return 0;
}