class Solution {
public:
    void letterComb(int i,string& str, vector<string>& ans,int n,string& digits, map<int,string> mp){
        if(i==n){
            ans.push_back(str);
            return;
        }
        string alpha  = mp[digits[i]-'0'];
        for(int ind = 0; ind<alpha.size(); ind++){
            str+=alpha[ind];
            letterComb(i+1,str,ans,n,digits,mp);
            str.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        string str = "";
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        letterComb(0,str,ans,digits.size(),digits,mp);
        return ans;
    }
};