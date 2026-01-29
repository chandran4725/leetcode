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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> wrapList;

        if(root == NULL) return wrapList;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            vector<int> subList;
            int n = q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                subList.push_back(node->val);
            }

            wrapList.push_back(subList);
        }

        return wrapList;
    }
};