class Solution {
public:
    bool bfs(vector<int>& nums, vector<bool>& vis,int idx){
        int n=nums.size();
        queue<int> q;
        q.push(idx);
        vis[idx]=true;

        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(nums[i]==0) return true;
            int next = i+nums[i];
            int prev = i-nums[i];
            if(next<n and next>=0 and !vis[next]){
                vis[next]=true;
                q.push(next);
            }
            if(prev<n and prev>=0 and !vis[prev]){
                vis[prev]=true;
                q.push(prev);
            }
        }
        return false;
    }
    // bool dfs(vector<int>& nums, vector<bool>& vis, int i){
    //     int n=nums.size();
    //     if(i<0 or i>=n) return false;
    //     if(vis[i]) return false;
    //     vis[i]=true;
    //     if(nums[i]==0) return true;
    //     int next = i+nums[i];
    //     int prev = i-nums[i];

    //     return dfs(nums,vis,next) or dfs(nums,vis,prev);
    // }
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        vector<bool> vis(n,false);
        return bfs(nums,vis,start);
    }
};