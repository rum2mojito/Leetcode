// 343. Integer Break

class Solution {
public:
    int integerBreak(int n) {
        vector<int> res{1, 1, 1, 2, 4, 6, 9};
        for (int i=7;i<=n;i++) {
            res.push_back(res[i-3]*3);
        }
        return res[n];
    }
};
