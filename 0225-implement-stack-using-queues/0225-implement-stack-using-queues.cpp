class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }
        int size = q.size();
        for(int i = 0; i<size-1; i++){
            int frontEle = q.front();
            q.pop();
            q.push(frontEle);
        }
        int reqEle  =q.front();
        q.pop();
        return reqEle;
    }
    
    int top() {
        if(q.empty()){
            return -1;
        }
        return q.back();
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