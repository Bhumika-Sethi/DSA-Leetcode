class Solution {
public:
    // piles[ith] - no of bananas
    // k - banana/hr
    // hrs for 1 pile = piles[ith]/k
    // Sum all the hrs if it is less than or equal than h, accepted
    // Min value of K is one, max is max of piles array
    // when k is max, no of hrs will be min

    long long calculateHrs(vector<int>& piles, int noOfBananasPerHr){
        long long TotalHrs = 0;
        for(auto it:piles){
            TotalHrs += ((long long)it/(long long)noOfBananasPerHr);
            if(it%noOfBananasPerHr){
                TotalHrs += 1;
            }
        }
        return TotalHrs;
    }



    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long valueForithBPH = calculateHrs(piles,mid);
            cout<<valueForithBPH<<endl;
            if(valueForithBPH<=h){
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