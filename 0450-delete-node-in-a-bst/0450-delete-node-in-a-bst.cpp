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
    TreeNode* findLast(TreeNode* node)
    {
        if(node->right == NULL) return node;
        return findLast(node->right);
    }

    TreeNode* helper(TreeNode* node)
    {
        if(node->right == NULL) return node->left;
        if(node->left == NULL) return node->right;

        TreeNode* rightChild = node->right;
        TreeNode* lastRightChild = findLast(node->left);

        lastRightChild->right = rightChild;

        return node->left;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key) return helper(root);

        TreeNode* node = root;

        while(node)
        {
            if(node->val > key)
            {
                if(node->left!= NULL && node->left->val == key)
                {
                    node->left = helper(node->left);
                    break;
                }
                else node = node->left;
            }
            else {
                if(node->right != NULL && node->right->val == key)
                {
                    node->right = helper(node->right);
                    break;
                }
                else node = node->right;
            }
        }

        return root;
    }
};