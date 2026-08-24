class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str;
        stack<int> st;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i]=='('){  //Opening parenthesis index
                st.push(i);
            }
            else if(s[i]==')'){  //Closing parenthesis -> remove that one pair
                if(!st.empty()){
                    st.pop();
                }
                else{     //What if no valid ( is there in that case mark it as invalid
                    s[i] = '*';
                }
            }
        }
         //What if we have no closing for the opening -> mark them in the string
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }

        for(int i = 0; i<n; i++){
            if(s[i]!='*'){
                str+=s[i];
            }
        }
        return str;
    }
};