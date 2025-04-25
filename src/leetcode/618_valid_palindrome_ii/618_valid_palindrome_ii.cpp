#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0; int right = n - 1;

        auto isPalindrome = [](string& s, int left, int right) -> bool {
            while(left < right) {
                if (s[left] != s[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };

        while(left < right) {
            if(s[left] != s[right]) {
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};