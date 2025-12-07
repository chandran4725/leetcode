class Solution {
public:
    void parenthesis(int left,int right,int n,vector<string> &res,string &s)
    {
        if(s.size() == 2*n)
        {
            res.push_back(s);
            return;
        }

        if(left < n)
        {
            s+='(';
            parenthesis(left+1,right,n,res,s);
            s.pop_back();
        }

        if(right < left)
        {
            s+=')';
            parenthesis(left,right+1,n,res,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        string s = "";

        parenthesis(0,0,n,res,s);

        return res;
    }
};