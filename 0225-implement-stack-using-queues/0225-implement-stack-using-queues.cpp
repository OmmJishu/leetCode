class MyStack {
private:
    deque<int> q1;
public:
    
    void push(int x) {
        q1.push_back(x);
    }
    
    int pop() {
        int a = q1.back();
        q1.pop_back();
        return a;
    }
    
    int top() {
        int res = q1.back();
        return res;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */