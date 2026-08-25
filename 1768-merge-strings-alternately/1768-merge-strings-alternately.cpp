class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word;

        int i = 0;
        int j = 0;

        int n = word1.size();
        int m = word2.size();

        while(i<n && j<m){
            word+=word1[i++];
            word+=word2[j++];
        }

        while(i<n){
            word+=word1[i++];
        }
        while(j<m){
            word+=word2[j++];
        }
        return word;
    }
};