#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> _stack, _min_stack;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        _stack.push(val);
        if(_min_stack.empty()) {
            _min_stack.push(val);
        } else {
            _min_stack.push(min(val, _min_stack.top()));
        }
    }
    
    void pop() {
        _stack.pop();
        _min_stack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return _min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */