class Solution {
public:
    void generate(int left,int right,int n,string s,vector<string> &ans)
    {
        if(s.size() == 2*n) 
        {
            ans.push_back(s);
            return;
        }

        if(left < n)
        {
            s.push_back('(');
            generate(left+1,right,n,s,ans);
            s.pop_back();
        }

        if(right < left)
        {
            s.push_back(')');
            generate(left,right+1,n,s,ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0,0,n,"",ans);
        return ans;
    }
};