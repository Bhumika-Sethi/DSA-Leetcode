class Solution {
public:
    bool check(string& s1, string& s2){
        if(s1.size()!=(s2.size()+1)){
            return false;
        }
        int ind1 = 0;
        int ind2 = 0;
        while(ind1<s1.size()){
            if(s1[ind1]==s2[ind2]){
                ind1++;
                ind2++;
            }
            else{
                ind1++;
            }
        }
        if(ind1==s1.size() && ind2==s2.size()){
            return true;
        }
        else{
            return false;
        }
    }
    static bool comp(string& s1, string& s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxLen = 0;
        sort(words.begin(),words.end(),comp);
        for(int ind = 0; ind<n; ind++){
            for(int prev_ind = 0; prev_ind<ind; prev_ind++){
                if(check(words[ind],words[prev_ind]) && dp[ind]<dp[prev_ind]+1){
                    dp[ind] = dp[prev_ind] + 1;
                }
            }
            if(maxLen<dp[ind]){
                maxLen = dp[ind];
            }
        }
        return maxLen;
    }
};