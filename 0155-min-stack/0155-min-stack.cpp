class MinStack {
    stack<int> s,mn;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            mn.push(val);
        }else{
            mn.push(min(mn.top(),val));
        }
        s.push(val);
    }
    
    void pop() {
        if(s.empty())return;
        s.pop();
        mn.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn.top();
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