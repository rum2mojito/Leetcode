// 807. Max Increase to Keep City Skyline

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        vector<int> right(grid.size(),0), top(grid[0].size(),0);
        int sum=0, res=0;
        
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (top[j] < grid[i][j]) {
                    top[j] = grid[i][j];
                }
                if (right[i] < grid[i][j]) {
                    right[i] = grid[i][j];
                }
                sum += grid[i][j];
            }
        }
        
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                res += top[j]<right[i]? top[j]:right[i];
            }
        }
        return res-sum;
    }
};
