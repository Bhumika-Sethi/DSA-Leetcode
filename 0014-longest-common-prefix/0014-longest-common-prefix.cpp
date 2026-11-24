class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        for(int i = 0; i<strs[0].size(); i++){
            char ch = strs[0][i];
            bool didMatch = true;

            for(int j = 1; j<n; j++){
                if(i>=strs[j].size() || ch!=strs[j][i]){
                    didMatch = false;
                    break;
                }
            }
            if(didMatch==false){
                return ans;
            }
            else{
                ans+=ch;
            }
        }
        return ans;
    }
};