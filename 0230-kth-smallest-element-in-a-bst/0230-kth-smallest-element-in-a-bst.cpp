/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* node, int k, int& ans, int& cnt) {
        if (node == NULL)
            return;

        traverse(node->left, k, ans, cnt);

        cnt += 1;
        if (cnt == k) {
            ans = node->val;
            return;
        }

        traverse(node->right, k, ans, cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cnt = 0;
        traverse(root, k, ans, cnt);
        return ans;
    }
};