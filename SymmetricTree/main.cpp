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

    if(root->val == -1)
        printf("null ");
    else
        printf("%d ", root->val);

    print(root->left);
    print(root->right);
}

TreeNode* tree_buider(const std::vector<int>& ints)
{
    if(ints.empty())
        return nullptr;

    size_t levels = 1;
    while(ints.size() >= std::pow(2, levels))
        levels++;
        
    size_t expected_leaves = std::pow(2, (levels-1));
    size_t l = 2 * levels - (ints.size() - 1L);
    size_t leaves = expected_leaves - l;

    std::vector<TreeNode*> nodes{2*levels+1, nullptr};

    for(int i = long(ints.size()-1); i >= 0; i--)
    {
        if(ints[i] == -1)
        {
            nodes[i] = nullptr;
        }
        else
        {
            TreeNode* n = i >= long(ints.size() - leaves) ? new TreeNode(ints[i], nullptr, nullptr) : new TreeNode(ints[i], nodes[i*2+1], nodes[i*2+2]);
            nodes[i] = n;
        }
    }

    return nodes.front();
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {            
        if(!root)
            return nullptr;
        
        TreeNode* tmp = root->left;
        root->left = root->right;            
        root->right = tmp; 

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    void preord(TreeNode* root, std::vector<int>* dst)
    {
        if(!root)
        {
            dst->push_back(-1);
            return;
        }
        
        dst->push_back(root->val);
        preord(root->left, dst);
        preord(root->right, dst);
    }

    bool isSymmetric(TreeNode* root)
    {
        if(!root)
            return false;
        TreeNode* invRight = invertTree(root->right);
        std::vector<int> a;
        std::vector<int> b;

        preord(root->left, &a);
        preord(invRight, &b);

        return a==b;
    }
};


int main()
{
    
    TreeNode* root1 = tree_buider({2, 3, -1, 1});

    print(root1);
    printf("\n");

    TreeNode* res = Solution().invertTree(root1);
    print(res);
    printf("\n");
}