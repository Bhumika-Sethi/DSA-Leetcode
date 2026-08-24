class Solution {
public:

    bool isPalidrome(int start, int end, string s){
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;


        while(left<=right && s[left]==s[right]){
            left++;
            right--;
        }

        return isPalidrome(left+1,right,s) || isPalidrome(left,right-1,s);
    }
};