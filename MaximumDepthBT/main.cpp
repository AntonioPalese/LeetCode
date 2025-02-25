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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        int l = 1 + maxDepth(root->left);
        int r = 1 + maxDepth(root->right);
        return l > r ? l : r;
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


int main()
{
    std::vector<int> ints{3,9,20,-1,-1,15,7};
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
    print(nodes.front());
    printf("\n");

    int depth = Solution().maxDepth(nodes.front());
    printf("depth : %d\n", depth);    
}