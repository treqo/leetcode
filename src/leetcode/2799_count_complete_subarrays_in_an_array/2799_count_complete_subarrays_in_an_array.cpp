#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ht;

        for(int i = 0; i < n; i++) {
            ht[nums[i]]++;
        }

        int distinct = ht.size();

        int cnt = 0;
        int left = 0; int right = 0;

        unordered_map<int,int> rolling_ht;

        while (right < n) {
            rolling_ht[nums[right]]++;
            while (rolling_ht.size() == distinct) {
                cnt += n - right;  
                if (--rolling_ht[nums[left]] == 0) {
                    rolling_ht.erase(nums[left]);
                }
                left++;
            }
            right++;
        }

        return cnt;
    }
};