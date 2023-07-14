class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int i = 0;
        while(i<q.size()-1){
            int ele = q.front();
            q.pop();
            q.push(ele);
            i++;
        }
    }
    
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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