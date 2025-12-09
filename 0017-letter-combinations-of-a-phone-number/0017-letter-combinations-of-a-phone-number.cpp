class Solution {
public:
    void findCombinations(int ind, string digits, string& s,
                          vector<string>& mapping, vector<string>& ans) {
        if (ind >= digits.size())
        {
            ans.push_back(s);
            return;
        }

        string str = mapping[digits[ind]-'0'];

        for(int i=0;i<str.size();i++)
        {
            s.push_back(str[i]);
            findCombinations(ind+1,digits,s,mapping,ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        string s;
        findCombinations(0,digits,s,mapping,ans);

        return ans;
    }
};