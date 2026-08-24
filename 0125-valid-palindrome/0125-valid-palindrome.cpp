#include<bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i = 0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z') ||(s[i]>='0' && s[i]<='9')){
                str+=s[i];
            }
        }
        int n = str.size();
        for(int i = 0; i<n/2; i++){
            if(str[i]!=str[n-i-1]){
                return false;
            }
        }
        return true;
    }
};