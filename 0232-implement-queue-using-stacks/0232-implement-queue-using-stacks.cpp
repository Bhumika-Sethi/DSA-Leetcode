class MyQueue {
public:
    stack<int> st;
    stack<int> dummySt; 
    MyQueue() {
       
    }
    
    void push(int x) {
        while(!dummySt.empty()){
            st.push(dummySt.top());
            dummySt.pop();
        }
        st.push(x);
    }
    
    int pop() {
        if(!dummySt.empty()){
            int ele = dummySt.top();
            dummySt.pop();
            return ele;
        }
        if(st.empty()){
            return -1;
        }
        while(!st.empty()){
            dummySt.push(st.top());
            st.pop();
        }
        int ele = dummySt.top();
        dummySt.pop();
        return ele;
    }
    
    int peek() {
         if(!dummySt.empty()){
            return dummySt.top();
         } 
         if(st.empty()){
            return -1;
         }   
         while(!st.empty()){
            dummySt.push(st.top());
            st.pop();
        }
        int ele = dummySt.top();
        return ele;
    }
    
    bool empty() {
        return st.empty() && dummySt.empty();
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