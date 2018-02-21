// 695. Max Area of Island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    int h = area (grid,i,j);
                    if (h>max) {
                        max = h;
                    }
                }
            }
        }
        return max;
    }
    
    int area (vector<vector<int>>& grid , int i, int j) {
        grid[i][j] = 0;
        int res = 1;
        if ( i+1<grid.size() && grid[i+1][j] == 1) {
            res+=area(grid,i+1,j);
        }
        if ( i-1>=0 && grid[i-1][j] == 1) {
            res+=area(grid,i-1,j);
        }
        if ( j+1<grid[0].size() && grid[i][j+1] == 1) {
            res+=area(grid,i,j+1);
        }
        if ( j-1>=0 && grid[i][j-1] == 1) {
            res+=area(grid,i,j-1);
        }
        return res;
    }
};
