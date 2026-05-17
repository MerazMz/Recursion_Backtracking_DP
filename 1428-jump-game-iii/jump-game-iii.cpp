class Solution {
public:
    // bool bfs(vector<int>& nums, vector<bool>& vis,int start){
    //     int n=nums.size();
    //     queue<int> q;
    //     if(start>=n or start<0) return false;
    //     q.push(start);
    //     vis[start]=true;
    //     while(!q.empty()){
    //         int curridx = q.front();
    //         q.pop();
    //         int currval = nums[curridx];
    //         if(currval==0) return true;
    //         int aheadidx = curridx+currval;
    //         int previdx = curridx-currval;
    //         if(aheadidx>=n || aheadidx<0 || previdx)
    //         if(!vis[aheadidx]){
    //             q.push(aheadidx);
    //             vis[aheadidx]=true;
    //         }
    //         if(!vis[previdx]){
    //             q.push(previdx);
    //             vis[previdx]=true;
    //         }
    //     }
    //     return false;
    // }
    bool dfs(vector<int>& nums, vector<bool>& vis, int i){
        int n=nums.size();
        if(i<0 or i>=n) return false;
        if(vis[i]) return false;
        vis[i]=true;
        if(nums[i]==0) return true;
        int next = i+nums[i];
        int prev = i-nums[i];

        return dfs(nums,vis,next) or dfs(nums,vis,prev);
    }
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        vector<bool> vis(n,false);
        return dfs(nums,vis,start);
    }
};