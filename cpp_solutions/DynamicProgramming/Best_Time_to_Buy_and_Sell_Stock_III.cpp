/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        	return 0;

        vector<int> profit(prices.size());
        // initialize
        int buy = 0;
        buy = prices[0];
        profit[0] = 0;

        for(int i=1; i<prices.size(); i++){
        	profit[i] = max(profit[i-1], prices[i] - buy);
        	buy = min(buy, prices[i]);
        }

        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; i--)
        {
        	best = max(best, sell - prices[i] + profit[i]);
        	sell = max(sell, prices[i]);
        }

        return best;
    }
};