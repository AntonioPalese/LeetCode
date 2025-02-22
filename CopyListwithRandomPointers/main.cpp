#include <cstdlib>
#include <vector>
#include <cassert>
#include <ctime>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL; 
        Node* act_head = NULL; 
        Node* shallow = head;

        std::unordered_map<Node*, Node*> st;
        while(shallow)
        {
            if(!newHead)
            {
                act_head = new Node(shallow->val);
                newHead = act_head;
            }
            else
            {
                Node* act = new Node(shallow->val);
                act_head->next = act;
                act_head = act;                                
            }

            st[shallow] = act_head;            
            shallow = shallow->next;
        }

        Node* tmp = newHead;
        while (head)
        {
            tmp->random = head->random ? st[head->random] : NULL;
            tmp = tmp->next;
            head = head->next;
        }

        return newHead;
    }
};

void print(Node* c)
{
    while(c != nullptr)
    {
        printf("val : %d, rnd : %d\n", c->val, c->random? c->random->val : -1);
        c = c->next;
    }
    printf("\n");
}

int main()
{
    std::vector<int> in1{0, 1, 2};
    std::vector<Node*> nodes(in1.size(), NULL);
    for(int i = in1.size()-1; i >= 0; i--)
    {
        Node * n = NULL;
        if(i == in1.size()-1)
            n = new Node(in1[i]);
        else
        {
            n = new Node(in1[i]);   
            n->next = nodes[i+1];
        }
        nodes[i] = n;            
    }

    srand((unsigned)time(0)); 
    for(auto& c : nodes)
    {        
        int i = (rand()%nodes.size()+1); 
        //printf("i : %d\n", i);
        c->random = i < nodes.size() ? nodes[i] : nullptr;
    }

    Node* deep_copy = Solution().copyRandomList(nodes.front());
    Node* original = nodes.front();

    print(original);
    print(deep_copy);    

    while(deep_copy)
    {
        assert(deep_copy != original);
        printf("deepcopy : %p, original : %p\n", deep_copy, original);
        deep_copy = deep_copy->next;
        original = original->next;
    }
}