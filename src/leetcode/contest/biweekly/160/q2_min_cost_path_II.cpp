#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int moveCost = (i+1) * (j+1);
                
                long long prevTop = (i-1 >= 0) ? dp[i-1][j] : -1;
                long long prevLeft = (j-1 >= 0) ? dp[i][j-1] : -1;
                
                long long prev = (prevTop == -1 || prevLeft == -1) ? 
                    max(prevTop, prevLeft) : min(prevTop, prevLeft);
                
                dp[i][j] = moveCost + prev + ((i==m-1 && j==n-1) ? 0LL : waitCost[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> q1 = {{1,2}}, q2 = {{3,5},{2,4}}, q3 = {{6,1,4},{3,2,5}};
    Solution soln;
    cout << soln.minCost(1,2,q1) << endl;
    cout << soln.minCost(2,2,q2) << endl;
    cout << soln.minCost(2,3,q3) << endl;
    return 0;
}
