#include <vector>
#include <iostream>
#include <cmath>

#define OPTIMAL

int minCoinsRecur(int i, int sum, std::vector<int> &coins) {
    if(sum == 0) return 0;
    if(sum < 0 || i == coins.size()) return INT_MAX;

    int take = INT_MAX;

    // take a coin only if its value is greater than 0
    if(coins[i]>0) {
        take = minCoinsRecur(i, sum-coins[i], coins);
        if(take != INT_MAX) take++;
    }

    // not take the coin
    int noTake = minCoinsRecur(i+1, sum, coins);

    return std::min(take, noTake);
}

int minCoins(std::vector<int> &coins, int sum) {
    int res = minCoinsRecur(0, sum, coins);
    return res != INT_MAX ? res : -1;
}

int main() {
    std::vector<int> coins = {9, 6, 5, 1};
    int sum = 19;
    std::cout << minCoins(coins, sum) << '\n';
    return 0;
}

