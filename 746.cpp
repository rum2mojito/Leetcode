// 746. Min Cost Climbing Stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> total(cost.size(),0);
        total[0] = cost[0];
        total[1] = cost[1];
        
        for (int i=2;i<cost.size();i++) {
            total[i] = min(total[i-1]+cost[i] , total[i-2]+cost[i]);
        }
        
        return min(total[cost.size() - 1], total[cost.size() - 2]);
    }
};
