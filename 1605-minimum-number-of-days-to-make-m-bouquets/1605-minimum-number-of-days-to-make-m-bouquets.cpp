class Solution {
public:
    bool countBouquets(vector<int>& bloomDay, int dayNo, int noOfBouquets, int flowers){
        long cnt = 0;
        long long noOfBouquetsFormed = 0;
        for(int i = 0; i<bloomDay.size(); i++){
            if(dayNo>=bloomDay[i]){
                cnt++;
            }
            else{
                noOfBouquetsFormed += ((long long)cnt/(long long)flowers);
                cnt = 0;
            }
        }
        noOfBouquetsFormed += ((long long)cnt/(long long)flowers);
        if((long long)noOfBouquets<=noOfBouquetsFormed){
            return true;
        }
        return false;
    } 
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*(long long)k>(long long)n){
            return -1;
        }
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(countBouquets(bloomDay,mid,m,k)){
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