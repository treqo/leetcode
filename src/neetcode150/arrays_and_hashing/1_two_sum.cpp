#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            int dif = target - nums[i];
            if(mp.find(dif) != mp.end()) {
                return {mp[dif], i};
            } else {
                mp[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};