class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();
        reverse(s.begin(),s.end());
        int j = n-1;
        while(i<j){
            if(s[i]==' '){
                i++;
            }
            else if(s[j]==' '){
                j--;
            }
            else{
                break;
            }
        }

        n = j;
        j = i;
        string ans;
        while(j<=n){
            if(s[j]==' '){
                // skip multiple spaces
                if (i == j) {
                    i++;
                    j++;
                    continue;
                }
                string word  = s.substr(i,j-i);
                reverse(word.begin(),word.end());
                ans += word;
                ans += ' ';
                i = j+1;
            }
            j++;
        }
        if(i<=n){
        string word  = s.substr(i,j-i);
        reverse(word.begin(),word.end());
        ans += word;
        i = j+1;
        }


        return ans;
    }
};