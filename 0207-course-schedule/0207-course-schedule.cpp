class Solution {
public:
    bool dfs(int src, vector<vector<int>>& edges, vector<bool>& vis,
    vector<bool>& recPath){
        vis[src]=true;
        recPath[src]=true;

        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            if(u==src){
                if(!vis[v]){
                    if(dfs(v,edges,vis,recPath)) return true;
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,edges,vis,recPath)) return false; //if cycle detected its not possible
            }
        }
        return true;
    }
};