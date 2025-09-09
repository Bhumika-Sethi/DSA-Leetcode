class MinStack {
public:
    stack<long> st;
    long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
            return;
        }
        if(mini<val){
            st.push(val);
        }
        else{
            long value = val;
            st.push(2*value-mini);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        if(st.top()>mini){
            st.pop();
        }
        else{
            mini = 2*mini - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>mini){
            return st.top();
        }
        else{
            return mini;
        }
    }
    
    int getMin() {
        return mini;
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