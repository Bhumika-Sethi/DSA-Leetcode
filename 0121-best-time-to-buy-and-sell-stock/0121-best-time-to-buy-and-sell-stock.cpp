class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bought = prices[0];
        for(int i = 1; i<prices.size(); i++){
            bought = min(bought,prices[i]);
            profit = max(profit,prices[i]-bought);
        }
        return profit;
    }
};