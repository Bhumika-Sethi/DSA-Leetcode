class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
//         s1 -> s2;
//         x -> s1;
//         s2 -> s1;
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int front = s1.top();
            s1.pop();
            s2.push(front);
        }
        s1.push(x);
        while(!s2.empty()){
            int front = s2.top();
            s2.pop();
            s1.push(front);
        }
    }
    
    int pop() {
        int ele = s1.top();
        s1.pop();
        return ele;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */