class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int i = 0; // buy
        int j = 1; // sell

        while (j < prices.size()) {
            if (prices[j] > prices[i]) {
                int profit = prices[j] - prices[i];
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            } else {
                i = j;
            }
            j++;
        }

        return maxProfit;
    }
};