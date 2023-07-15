struct compare{
    bool operator()(pair<int,int>& p1, pair<int,int>& p2){
        return p1.second<p2.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        
        while(k){
            v.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return v;
    }
};