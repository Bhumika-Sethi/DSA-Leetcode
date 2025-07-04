#include<bits/stdc++.h>
class Solution {
public:
    bool weightForNoOfDaysCalculator(vector<int>& weights, int capacityOfShip, int days){
        int weightTotal = 0;
        int day = 1;
        for(int i = 0; i<weights.size(); i++){
            weightTotal += weights[i];
            if(weightTotal>capacityOfShip){
                day++;
                weightTotal = weights[i];
            }
            else if(weightTotal==capacityOfShip && i!=(weights.size()-1)){
                day++;
                weightTotal = 0;
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(weightForNoOfDaysCalculator(weights,mid,days)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};