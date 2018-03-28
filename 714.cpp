// 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> hold(prices.size(),0), unhold(prices.size(),0);
        hold[0] -= prices[0];
        for (int i=1;i<prices.size();i++) {
            hold[i] = max (hold[i-1], unhold[i-1]-prices[i]);
            unhold[i] = max (unhold[i-1], hold[i]+prices[i]-fee);
        }
        return unhold[prices.size()-1];
    }
};
