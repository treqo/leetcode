#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(auto num : nums) {
            if(mp[num]++ > 0) return true;
        }

        return false;
    }
};