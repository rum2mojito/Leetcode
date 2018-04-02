// 526. Beautiful Arrangement

class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        vector<int> visit(N+1, 0);
        helper(N, visit, 1, res);
        return res;
    }
    
    void helper (int n, vector<int> &visit, int pos, int &res) {
        if (pos > n) {
            ++res;
            return;
        }
        
        for (int i=1; i<=n; ++i) {
            if (visit[i] == 0 && (i%pos == 0 || pos%i == 0)) {
                visit[i] = 1;
                helper (n, visit, pos+1, res);
                visit[i] = 0;
            }
        }
    }
};
