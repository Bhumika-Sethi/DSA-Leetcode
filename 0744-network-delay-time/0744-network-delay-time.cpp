class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i = 0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,k});
        time[k] = 0;

        while(!pq.empty()){
            int timeConsumedTillNow = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int  timeTaken= it.second;

                if(time[node]!=INT_MAX && timeConsumedTillNow + timeTaken < time[adjNode]){
                    time[adjNode] = timeConsumedTillNow + timeTaken;
                    pq.push({timeConsumedTillNow + timeTaken,adjNode});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i<time.size(); i++){
            if(time[i]==INT_MAX){
                return -1;
            }
            maxi = max(maxi,time[i]);
        }
        return maxi;
    }
};