#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int _min = prices[0], _max = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > _min) {
                profit += prices[i] - _min;
                _min = prices[i];
            } else {
                _min = prices[i];
            }
        }
        return profit;
    }
};