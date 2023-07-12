class Solution {
    
    bool isPalidrome(int start, int end, string& s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void palpartition(int ind, int n, string& s, vector<string>& ds, vector<vector<string>>& ans){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i = ind; i<n; i++){
            if(isPalidrome(ind,i,s)){
                ds.push_back(s.substr(ind,i-ind+1));
                palpartition(i+1,n,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        palpartition(0,s.size(),s,ds,ans);
        return ans;
    }
};