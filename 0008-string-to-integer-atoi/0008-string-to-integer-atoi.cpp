class Solution {
public:
    int func(int i, string& s, long long res, int sign, bool started) {
        if (i == s.size())
            return res * sign;

        if (!started && s[i] == ' ')
            return func(i + 1, s, res, sign, false);

        if (!started && (s[i] == '+' || s[i] == '-'))
            return func(i + 1, s, res, s[i] == '-' ? -1 : 1, true);

        if (isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if (res > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            return func(i + 1, s, res, sign, true);
        }

        return res * sign;
    }

    int myAtoi(string s) { return func(0, s, 0, 1, false); }
};