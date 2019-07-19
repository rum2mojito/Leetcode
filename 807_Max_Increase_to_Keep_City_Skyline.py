class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        h_list = [0] * len(grid[0])
        v_list = [0] * len(grid)
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                h_list[j] = max(h_list[j], grid[i][j])
                v_list[i] = max(v_list[i], grid[i][j])
        res = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                res += min(h_list[j], v_list[i]) - grid[i][j]
        return res
        
