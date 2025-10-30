class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int,int> mp;
        int maxLen = 0;
        int l = 0, r = 0;
        int maxFreq = 0;
        while(r<s.size()){
            mp[s[r]]++;
            maxFreq = max(maxFreq,mp[s[r]]);
            while((r-l+1)-maxFreq>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                maxFreq = 0;
                for(auto it: mp){
                    maxFreq = max(maxFreq,it.second);
                }
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};