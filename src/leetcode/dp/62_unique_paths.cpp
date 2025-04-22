#include <iostream>
#include <vector>
#include <climits>
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

int main() {
    Solution sol;
    
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = sol.jump(nums);
    
    cout << "Minimum number of jumps: " << result << endl;  // Output the result

    return 0;
}
