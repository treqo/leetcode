#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int n = s.size();
        int freq[26];
        
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int f : freq) {
            if(f != 0) return false;
        }

        return true;
    }
};