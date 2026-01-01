class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0, tenCount = 0, twentyCount = 0;
        int n = bills.size();
        for(int i = 0; i<n; i++){
            if(bills[i]==5){
                fiveCount++;
            }
            else if(bills[i]==10){
                if(fiveCount>=1){
                    fiveCount--;
                    tenCount++;
                }
                else{
                    return false;
                }
            }
            else{
                if(tenCount>=1 && fiveCount>=1){
                    tenCount--;
                    fiveCount--;
                    twentyCount++;
                }
                else if(fiveCount>=3){
                    fiveCount -= 3;
                    twentyCount++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};