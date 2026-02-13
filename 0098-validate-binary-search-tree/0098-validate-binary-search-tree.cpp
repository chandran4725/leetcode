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
    bool traverse(TreeNode* node,long long mini, long long maxi)
    {
        if(!node) return true;

        if(node->val >= maxi || node->val <= mini) return false;

        return traverse(node->left,mini,node->val) && traverse(node->right,node->val,maxi);
    }

    bool isValidBST(TreeNode* root) {
        

        return traverse(root,LLONG_MIN, LLONG_MAX);
    }
};