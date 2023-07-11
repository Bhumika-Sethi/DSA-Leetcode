class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i = 0; i<n; i++){
            map<char,int> mp;
            int j;
            for(j = i; j<n; j++){
                if(mp[s[j]]){
                    break;
                }
                mp[s[j]]++;
            }
            maxi = max(maxi,j-i);
        }
        return maxi;
    }
};