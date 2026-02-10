/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void generateSubTree(TreeNode* node,vector<int>& ans)
    {
        if(node == NULL) return;

        ans.push_back(node->val);

        generateSubTree(node->left,ans);
        generateSubTree(node->right,ans);
    }

    TreeNode* traverse(TreeNode* node,int val)
    {
        if(node == NULL) return NULL;

        if(node->val == val)
        {
            return node;
        } 
        else if(node->val > val) return traverse(node->left,val);
        return traverse(node->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return traverse(root,val);
        
        
    }
};