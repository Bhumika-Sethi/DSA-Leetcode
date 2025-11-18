class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        vector<int> costt(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        q.push({0,{src,0}});
        costt[src] = 0;
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            for(auto it:adj[node]){
                if(stop+1>k+1){
                    continue;
                }
                if(cost+it.second<costt[it.first]){
                    costt[it.first] = cost+it.second;
                    q.push({stop+1,{it.first,costt[it.first]}});
                }
            }
        }
        
        if(costt[dst]!=INT_MAX){
            return costt[dst];
        }
        return -1;
    }
};