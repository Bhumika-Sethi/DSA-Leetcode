class Solution {
public:
    double myPow(double x, int n) {
        // Binary Exponention
        // We'll not iterate over the number n but the binary form of it
        // For eg: x=8, binaryForm = 1001 which is logn + 1
        // So by doing so we are reducing the time complexity from n to logn

        // Edge cases:
        if(n==0){
            return 1.00;
        }
        if(x==1.00){
            return 1;
        }
        if(x==-1.00){
            if(n%2==0){
                return 1.00;
            }
            else{
                return -1.00;
            }
        }
        long binaryForm = n; // It is the number itself - on the fly we are converting it to binaryForm
        if(n<0){ //If n is negative that means we need to change x to 1/x; so new x is 1/x and then turn binaryForm to positive
            x = 1/x;
            binaryForm = -binaryForm;
        }
        double ans = 1;
        while(binaryForm>0){
            if(binaryForm%2==1){ //If the value of binary form has 1 then multiply by ans 
                ans *= x;
            }
            x *= x; // For next we are updating the value of x to x2 as for every increase in place, we get powered multiplied by 2
            binaryForm/=2; // to get the next digit of binary form
        }
        return ans;
    }
};