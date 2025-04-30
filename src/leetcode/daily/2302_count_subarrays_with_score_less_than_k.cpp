#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long result = 0;

        for(int left = 0, right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while(sum * (right - left + 1) >= k && left <= right) {
                sum -= nums[left++];
            }
            result += right - left + 1;
        }

        return result;
    }
};