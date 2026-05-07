class Solution {
public:
    // int bfs(vector<vector<int>>& adj, int src){
    //     int n = adj.size();
    //     queue<int> q;
    //     vector<bool> vis(n,false);
    //     q.push(src);
    //     vis[src] = true;
    //     int ans = INT_MIN;
    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();
    //         ans = max(ans,u);
    //         for(int v : adj[u]){
    //             if(!vis[v]){
    //                 q.push(v);
    //                 vis[v] = true;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n);
        vector<int> s(n);
        vector<int> ans(n);
        p[0] = nums[0];
        s[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            p[i] = max(p[i-1], nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            s[i] = min(s[i+1], nums[i]);
        }
        ans[n-1]=p[n-1];
        // for(int i=0;i<n-1;i++){
        //     if(p[i]<=s[i+1]){
        //         ans[i]=p[i];
        //     }else if(p[i]>s[i+1]){
        //         ans[i]=p[i+1];
        //     }
        // }

        for(int i=n-2;i>=0;i--){
            if(p[i]<=s[i+1]){
                ans[i]=p[i];

            }else if(p[i]>s[i+1]){
                
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};