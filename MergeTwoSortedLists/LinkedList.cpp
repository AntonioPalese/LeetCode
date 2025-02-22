#include "LinkedList.h"

LinkedList::LinkedList(std::vector<int> vals)
{
    nodes.resize(vals.size());
    for(int i = vals.size()-1; i >= 0; i--)
    {
        ListNode* act = i == vals.size()-1 ? new ListNode(vals[i], nullptr) : new ListNode(vals[i], nodes[i+1]);
        nodes[i] = act;
    }
}

LinkedList::~LinkedList()
{
    for(int i = 0; i < nodes.size(); i++)
    {
        delete nodes[i];
    }
}
