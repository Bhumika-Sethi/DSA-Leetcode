class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        int cnt = 0;
        for(int i = 0; i<isConnected.size(); i++){
            for(int j = 0; j<isConnected[i].size(); j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};