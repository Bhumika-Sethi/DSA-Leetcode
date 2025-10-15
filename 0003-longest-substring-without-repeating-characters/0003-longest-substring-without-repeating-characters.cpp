class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxLen = 0;
        int n = s.size();
        map<char,int> mp;
        while(r<n){
            if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l){
                l = mp[s[r]] + 1;
            }
            int len = r - l + 1;
            maxLen = max(maxLen,len);
            mp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};