class StockSpanner {
    vector<int> arr;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int n = arr.size();
        int cnt = 0;
        for(int i = n-1; i>=0; i--){
            if(arr[i]<=price){
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */