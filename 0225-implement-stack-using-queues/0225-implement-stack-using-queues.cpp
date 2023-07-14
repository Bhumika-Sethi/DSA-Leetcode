class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
//        x -> q2;
//         q1 -> q2;
//         q2 -> q1;
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int frot = q1.front();
            q2.push(frot);
            q1.pop();
        }
//         swap q1, q2 is eqivalent to transfer all the element one by one from q2 to q1
        swap(q1,q2);
        // while(!q2.empty()){
        //     int fron = q2.front();
        //     q2.pop();
        //     q1.push(fron);
        // }
    }
    
    int pop() {
        int ele = q1.front();
        q1.pop();
        return ele;
        
    }
    
    int top() {
        return q1.front();
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