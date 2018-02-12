// 521. Longest Uncommon Subsequence I

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b)
            return -1;
        else {
            return (a.length()>=b.length()? a.length():b.length());
        }
    }
};
