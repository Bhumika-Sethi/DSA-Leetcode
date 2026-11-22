class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
         while(i<n && s[i]==' '){
            i++;
         }

         int sign = 1;

         if(s[i]=='+'){
            i++;
         }
         else if(s[i]=='-'){
            sign = -1;
            i++;
         }

         long long int res = 0;
         while(i<n && isdigit(s[i])){
            int lastDigit = s[i] - '0';
            res = res*10 + lastDigit;

            if(sign == 1 && res>=INT_MAX){
                return INT_MAX;
            }
            else if(sign == -1 && -res<=INT_MIN){
                return INT_MIN;
            }
            i++;
         }
         return (int)(sign*res);
    }
};