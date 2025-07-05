#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string concatHex36(int n) {
        string hexadecimal = intToX(n*n, 16);
        string hexatrigesimal = intToX(n*n*n, 36);
        string result = hexadecimal + hexatrigesimal;
        return result;
    }

    string intToX(int n, int base) {
        string res = "";
        stack<char> st;
        while(n > 0) {
            int modulus = n % base;
            if(modulus >= 0 && modulus <= 9) {
                st.push('0'+modulus);
            } else {
                st.push('A'+modulus-10);
            }
            n /= base;
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

int main() {
	Solution soln;
	cout << soln.concatHex36(13) << endl;

	return 0;
}
