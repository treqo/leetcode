#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groups(37, 0);

        for(int i = 1; i <= n; i++) {
            groups[getSumOfDigits(i)]++;
        }

        int largest_group_size = 0;
        int cnt = 0;
        for(int i = 1; i < groups.size(); i++) {
            if(groups[i] > largest_group_size) {
                largest_group_size = groups[i];
                cnt = 1;
            } else if(groups[i] == largest_group_size) {
                cnt++;
            }
        }

        return cnt;
    }

    int getSumOfDigits(int x) {
        int sum_of_digits = 0;
        while(x > 0) {
            sum_of_digits += x % 10;
            x /= 10;
        }
        return sum_of_digits;
    }
};