class Solution {
public:
    void reverse(string& str) {
        int i = 0;
        int j = str.size() - 1;

        while (i < j) {
            swap(str[i++], str[j--]);
        }
    }

    void reverseWord(int ind, string& str, string& ans, string& sub) {
        if (str[ind] != ' ')
            sub += str[ind];

        if (ind == 0) {
            if (!sub.empty()) {
                reverse(sub);
                ans += sub;
                ans += ' ';
            }
            return;
        }

        if (str[ind] == ' ') {
            if (!sub.empty()) {
                reverse(sub);
                ans += sub;
                ans += ' ';
                sub = "";
            }
        }

        reverseWord(ind - 1, str, ans, sub);
    }

    string reverseWords(string s) {
        string ans = "";
        string sub = "";
        reverseWord(s.size() - 1, s, ans, sub);
        if(!ans.empty()) ans.pop_back();
        return ans;
    }
};