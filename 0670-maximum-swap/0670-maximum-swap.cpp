class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> digitplacementinarray(10,-1);
        for(int i = 0; i<n; i++){
            int curr_digit = numStr[i]-'0';
            digitplacementinarray[curr_digit] = i;
        }

        for(int i = 0; i<n; i++){
            int curr_digit = numStr[i]-'0';
            for(int d = 9; d> curr_digit; d--){
                if(i<digitplacementinarray[d]){
                    swap(numStr[i],numStr[digitplacementinarray[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};