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
    int traverse(TreeNode* node,int ind)
    {
        if(node == NULL) return ind;

        int left = traverse(node->left,ind+1);
        int right = traverse(node->right,ind+1);

        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return traverse(root,0);
    }
};