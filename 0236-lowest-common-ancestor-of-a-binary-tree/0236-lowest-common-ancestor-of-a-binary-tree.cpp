/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* traverse(TreeNode* node,TreeNode* x,TreeNode* y)
    {
        if(node == NULL || node == x || node == y) return node;

        

        TreeNode* left = traverse(node->left,x,y);
        TreeNode* right = traverse(node->right,x,y);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return node;

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return traverse(root,p,q);
        
    }
};