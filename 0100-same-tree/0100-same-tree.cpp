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
    void traverse(TreeNode* node,vector<int>& arr)
    {
        if(node == NULL) 
        {
            arr.push_back(INT_MIN);
            return;
        }

        arr.push_back(node->val);
        traverse(node->left,arr);
        traverse(node->right,arr);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> arr1;
        vector<int> arr2;

        traverse(p,arr1);
        traverse(q,arr2);

        int ind = 0;
        int n = arr1.size();
        int m = arr2.size();

        if(n == 0 || m == 0) return false;

        while(ind < n && ind < m)
        {
            if(arr1[ind] != arr2[ind]) return false;
            ind++;
        }

        return true;
    }
};