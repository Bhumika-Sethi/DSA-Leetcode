class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        string str="";
        int carry = 0;
        int sum = 0;
        int i = n-1; 
        int j = m-1;

        while(i>=0 || j>=0 || carry){
            sum = 0;

            if(i>=0){
                sum+=num1[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=num2[j]-'0';
                j--;
            }
            if(carry>0){
                sum+=carry;
            }

            str+= to_string(sum%10);
            carry = sum/10;
        }

        reverse(str.begin(),str.end());
        return str;
    }
};