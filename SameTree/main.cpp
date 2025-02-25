#include <vector>
#include <stack>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void preOrder(TreeNode* root, std::vector<int>& dst)
    {
        if(!root)
        {
            dst.push_back(INT_MIN);
            return;
        }
        dst.push_back(root->val);
        preOrder(root->left, dst);
        preOrder(root->right, dst);
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::vector<int> p_traverse;
        std::vector<int> q_traverse;
        preOrder(p, p_traverse);
        preOrder(q, q_traverse);

        return q_traverse == p_traverse;
    }
};


void print(TreeNode* root)
{
    if(!root)
        return;

    if(root->val == -1)
        printf("null ");
    else
        printf("%d ", root->val);

    print(root->left);
    print(root->right);
}

TreeNode* tree_buider(const std::vector<int>& ints)
{
    std::vector<TreeNode*> nodes{ints.size(), nullptr};
    int levels = ints.size() / 2;
    int leafs = std::pow(2, levels-1);
    for(int i = ints.size()-1; i >= 0; i--)
    {
        if(ints[i] == -1)
        {
            nodes[i] = nullptr;
        }
        else
        {
            TreeNode* n = i >= (ints.size() - leafs) ? new TreeNode(ints[i], nullptr, nullptr) : new TreeNode(ints[i], nodes[i*2+1], nodes[i*2+2]);
            nodes[i] = n;
        }
    }

    return nodes.front();
}


int main()
{
    
    TreeNode* root1 = tree_buider({1, 2});
    TreeNode* root2 = tree_buider({1, -1, 2});

    print(root1);
    printf("\n");

    print(root2);
    printf("\n");

    bool res = Solution().isSameTree(root1, root2);
    printf("depth : %s\n", res ? "true" : "false");
}