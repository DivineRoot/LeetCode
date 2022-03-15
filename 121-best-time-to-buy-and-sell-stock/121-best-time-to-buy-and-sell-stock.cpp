
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProf = 0, minPrice = INT_MAX;
        for(auto it: prices){
            //If minPrice < currStockPrice --> minPrice = currStockPrice else it'll not change.
            minPrice = min(minPrice, it);
            
            // Max Profit = max((currStockPrice - minPrice), maxProfit)
            maxProf = max(it - minPrice, maxProf);
        }
        return maxProf;
    }
};