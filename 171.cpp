// 171. Excel Sheet Column Number

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0 , l = 0;
        for (int i=s.length()-1;i>=0;i--) {
            res += pow (26,l)*(s[i]-'A'+1);
            l++;
        }
        return res;
    }
};
