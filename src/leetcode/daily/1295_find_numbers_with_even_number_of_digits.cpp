#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto num : nums) {
            bool even_parity = true;
            while(num > 0) {
                even_parity = !even_parity;
                num /= 10;
            }
            count += even_parity;
        }
        return count;
    }
};