class Solution {
public:
    bool bfs(int node, vector<int>& col, vector<vector<int>>& adj){
        queue<int> q;
        q.push(node);
        col[node] = 1;

        while(!q.empty()){
            int curr_node = q.front();
            q.pop();

            for(auto it: adj[curr_node]){
                if(col[it]==-1){
                    col[it] = !col[curr_node];
                    q.push(it);
                }
                else if(col[it]==col[curr_node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);

        for(int i = 0; i<graph.size(); i++){
            if(color[i]==-1){
                if(bfs(i,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};