class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        if (s1.empty()) {
            return -1;
        } else {
            while (!s1.empty()) {
                auto top = s1.top();
                s1.pop();
                s2.push(top);
            }

            int val = s2.top();
            s2.pop();

            while (!s2.empty()) {
                auto top = s2.top();
                s2.pop();
                s1.push(top);
            }
            return val;
        }
    }

    int peek() {
        while (!s1.empty()) {
            auto top = s1.top();
            s1.pop();
            s2.push(top);
        }

        int val = s2.top();

        while (!s2.empty()) {
            auto top = s2.top();
            s2.pop();
            s1.push(top);
        }
        return val;
    }

    bool empty() { return s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */