#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 1));

        if(obstacleGrid[0][0]) return 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else if(!(i==0 && j==0)) {
                    dp[i][j] = (i == 0) ? dp[i][j-1] & 1
                        : (j == 0) ? dp[i-1][j] & 1 : dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    sol.uniquePathsWithObstacles(obstacleGrid);

    return 0;
}
