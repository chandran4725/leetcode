class Solution {
public:
    int convert(char ch) {
        switch (ch) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {

            int curr = convert(s[i]);
            if (i + 1 < n) {
                int next = convert(s[i + 1]);

                if (next > curr) {
                    sum += (next - curr);
                    i++;
                    continue;
                }
            } 

            sum += curr;
        }
        return sum;
    }
};