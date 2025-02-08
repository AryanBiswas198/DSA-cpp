#include<bits/stdc++.h>
class MinStack {
public:
    stack<pair<int, int>> st;
    int mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
        }
        else{
            mini = min(st.top().second, val);
        }
        st.push({val, mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()) {
            return -1;
        }
        return st.top().second;
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