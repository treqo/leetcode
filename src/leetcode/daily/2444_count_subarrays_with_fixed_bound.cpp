#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long result = 0;
        int minIndexLatest = -1, maxIndexLatest = -1, startIndex = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > maxK || nums[i] < minK) {
                minIndexLatest = -1;
                maxIndexLatest = -1;
                startIndex = i + 1;
            }
            if(nums[i] == minK) minIndexLatest = i;
            if(nums[i] == maxK) maxIndexLatest = i;
            result += max(0, min(minIndexLatest,maxIndexLatest) - startIndex + 1);
        }

        return result;
    }
};