class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        int M = 1e9 + 7;
        dp[0][0] = 1;
        
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<target+1; j++) {
                for(int m=1; m<k+1; m++) {
                    if(j-m >= 0)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-m]) % M;
                }
            }
        }
#if 0
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<target+1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
#endif
        return dp[n][target];
    }
};
