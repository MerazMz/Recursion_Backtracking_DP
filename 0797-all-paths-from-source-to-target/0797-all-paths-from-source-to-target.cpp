class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, int src, vector<int>& path){
        int target = graph.size()-1;
        path.push_back(src);
        if(src==target){
            ans.push_back(path);
        }else{
            for(int v:graph[src]){
                dfs(graph,v,path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph,0,path);
        return ans;
    }
};