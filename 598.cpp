// 598. Range Addition II

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a=m , b=n;
        for (int i=0;i<ops.size();i++) {
            if (ops[i][0]<a && ops[i][0]<m) {
                a = ops[i][0];
            }
            if (ops[i][1]<b && ops[i][1]<n) {
                b = ops[i][1];
            }
        }
        return a*b;
    }
};
