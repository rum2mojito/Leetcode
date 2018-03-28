// 650. 2 Keys Keyboard

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(2,0);
        
        for (int i=2;i<=n;i++) {
            for (int j=i/2;j>=1;j--) {
                if (i%j == 0) {
                    dp.push_back(dp[j]+i/j);
                    break;
                }
            }
            if (dp.size() != i+1) {
                dp.push_back(i);
            }
        }
        return dp[n];
    }
};
