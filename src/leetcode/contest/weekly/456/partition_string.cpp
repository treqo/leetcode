#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<string> partitionString(string s) {
            int n = s.size();
            unordered_set<string> uset;
            vector<string> segments;
            string segment = "";
            for(int i = 0; i < n; i++) {
                segment += s[i];
                if(uset.find(segment) == uset.end()) {
                    uset.insert(segment);
                    segments.push_back(segment);
                    segment.clear();
                }
            }
            return segments;
        }
    };

int main() {
    Solution soln = Solution();
    string s = "abbccccd";
    vector<string> segments;
    segments = soln.partitionString(s);
    for(auto& str : segments) {
        cout << str << endl;
    }
}