#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1(nums1.begin(), nums1.end());
        unordered_set<int> uset2(nums2.begin(), nums2.end());
        vector<int> result;

        for(auto num : uset1) {
            if(uset2.find(num) != uset2.end()) result.push_back(num);
        }
        
        return result;
    }
};