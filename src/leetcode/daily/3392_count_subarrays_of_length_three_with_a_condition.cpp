#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int sum = nums[0] + nums[2];
        for(int i = 1; i < n - 1; i++) {
            
        }
        return count;
    }
};