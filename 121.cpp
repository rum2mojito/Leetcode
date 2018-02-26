// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<int> res(prices.size(),0);
        int max = 0 , min = prices[0];
        
        for (int i=1;i<prices.size();i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            if (prices[i-1] < prices[i]) {
                res[i] = prices[i]-min;
                if (res[i] > max) {
                    max = res[i];
                }
            }
        }
        
        return max;
    }
};
