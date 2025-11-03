class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj)==true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
// If not a part of cycle then it would be eventually safe only as it would end at terminal node
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> pathVis(graph.size(),0);

        for(int i = 0; i<graph.size(); i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,graph);
            }
        }
        vector<int> safenodes;
        for(int i = 0; i<graph.size(); i++){
            if(pathVis[i]==0){
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};