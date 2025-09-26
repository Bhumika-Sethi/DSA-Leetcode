class Solution {
public:
    void validParanthesis(int open, int close, string s, int n, vector<string>& ans){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }

        if(open<n){
            validParanthesis(open+1,close,s+'(',n,ans);
        }
        if(close<open){
            validParanthesis(open,close+1,s+')',n,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
     vector<string> ans;
     validParanthesis(0,0,"",n,ans);
     return ans;   
    }
};