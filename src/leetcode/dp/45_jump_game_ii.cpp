#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            int max_jump = nums[i];
            for(int j = i; j < n && j <= i + max_jump; j++) {
                dp[j] = min(dp[i]+1, dp[j]);
            }
        }

        return dp[n-1];
    }
};