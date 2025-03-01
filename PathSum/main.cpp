#include <vector>
#include <stack>
#include <stdio.h>
#include <cmath>
//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(TreeNode* root)
{
    if(root == nullptr)
        return;

    printf("%d ", root->val);

    print(root->left);
    print(root->right);
}

TreeNode* tree_buider(const std::vector<int>& ints)
{
    std::vector<TreeNode*> nodes{ints.size(), nullptr};
    size_t levels = 1;
    while(ints.size() >= std::pow(2, levels))
        levels++;
        
    int leafs = std::pow(2, levels-1);
    for(int i = ints.size()-1; i >= 0; i--)
    {
        TreeNode* n = i >= (ints.size() - leafs) ? new TreeNode(ints[i], nullptr, nullptr) : new TreeNode(ints[i], nodes[i*2+1], nodes[i*2+2]);
        nodes[i] = n;
    }

    return nodes.front();
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return false;
            
        if(!root->left && !root->right)
            return targetSum - root->val == 0;
    
        bool left = false;
        bool right = false;
        if(root->left)
            left = hasPathSum(root->left, targetSum - root->val);
        if (root->right)
            right = hasPathSum(root->right, targetSum - root->val);   
                     
        return left || right;
        
    }
};


int main()
{    
    TreeNode* root1 = tree_buider({1, 2, -1});

    print(root1);
    printf("\n");

    bool res = Solution().hasPathSum(root1, 1);
    printf("res : %s\n", res ? "True" : "False");
}