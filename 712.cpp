// 712. Minimum ASCII Delete Sum for Two Strings

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum=0;
        vector<vector<int>> res (s1.length()+1,vector<int>(s2.length()+1,0));
        
        for (int i=0;i<s1.length();i++) {
            sum += (int)s1[i];
        }
        for (int i=0;i<s2.length();i++) {
            sum += (int)s2[i];
        }
        
        for (int i=1;i<s1.length()+1;i++) {
            for (int j=1;j<s2.length()+1;j++) {
                if (s1[i-1] == s2[j-1])
                    res[i][j] = res[i-1][j-1] + (int)s1[i-1];
                else {
                    res[i][j] = res[i-1][j] > res[i][j-1]? res[i-1][j] : res[i][j-1];
                }
            }
        }
        
        sum -= res[s1.length()][s2.length()]*2;
        return sum;                        
    }
};
