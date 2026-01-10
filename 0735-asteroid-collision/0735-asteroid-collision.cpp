class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i<n; i++){
            if(asteroids[i]>0){
                // Case 1: when stack is empty - we can obviously push
                // Case 2: when there is positive element in the stack - we can obviously push
                // Case 3: when there is negative element we can still push in the positive element on top of it as they are alreading going in opposite direction so they won't collide
                st.push(asteroids[i]);
            }
            else{
                // Case 1: If the stack is empty() - then just push
                // Case 2: If the stack is having negative element at top - then just push
                // Case 3: If the stack is having positive element at top - 
                //       - then compare the size,
                //      - pop till the size of st.top()<=negElement
                //      - when it st.top>negElement that menas the neElement got destroyed

                if(st.empty() || (!st.empty() && st.top()<0)){
                    st.push(asteroids[i]);
                }
                else{
                    int flag = 0;
                    int lastEle;
                    while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                        flag=1;
                        lastEle = st.top();
                        st.pop();
                    }

                    if(!st.empty() && st.top()>0 && st.top()==abs(asteroids[i])){
                        st.pop();
                    }
                    else if(st.empty() ||(!st.empty() && st.top()<0)){
                        st.push(asteroids[i]);
                    }
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};