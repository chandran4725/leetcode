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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;

        todo.push({root,{0,0}});

        while(!todo.empty())
        {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;

            int ver = p.second.first, lev = p.second.second;

            nodes[ver][lev].insert(node->val);

            if(node->left) todo.push({node->left,{ver-1,lev+1}});
            if(node->right) todo.push({node->right,{ver+1,lev+1}});
        }

        vector<vector<int>> ans;

        for(auto p : nodes)
        {
            vector<int> col;

            for(auto q : p.second)
            {
                for(int i : q.second)
                {
                    col.push_back(i);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};