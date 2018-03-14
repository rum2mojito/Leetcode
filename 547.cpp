// 547. Friend Circles

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        for (int i=0;i<M.size();i++) {
            if (M[i][i] == 1) {
                dfs (M,i,i);
                res++;
            }
        }
        return res;
    }
    
    void dfs (vector<vector<int>>& M, int x, int y) {
        M[x][x] = 0;
        M[y][y] = 0;
        M[x][y] = 0;
        M[y][x] = 0;
        for (int j=0;j<M[0].size();j++) {
            if (M[x][j] == 1) {
                dfs (M,x,j);
            }
        }
        for (int j=0;j<M[0].size();j++) {
            if (M[y][j] == 1) {
                dfs (M,y,j);
            }
        }
    }
};
