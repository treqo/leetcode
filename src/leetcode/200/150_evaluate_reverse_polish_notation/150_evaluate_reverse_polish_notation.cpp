#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string& s : tokens) {
            if(isOperator(s)) {
                int first_term = st.top(); st.pop();
                int second_term = st.top(); st.pop();

                if(s == "+") {
                    st.push(second_term + first_term);
                } else if(s == "-") {
                    st.push(second_term - first_term);
                } else if(s == "*") {
                    st.push(second_term * first_term);
                } else {
                    st.push(second_term / first_term);
                }
            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }

    bool isOperator(string& s) {
        return s == "+" || s == "-" || s == "/" || s == "*";
    }
};