class Solution {
public:
    int bfs(vector<int>& nums, vector<bool>& vis, unordered_map<int,vector<int>>& map){
        int n=nums.size();
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int count=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front();
                q.pop();
                if(i == n-1) return count;
                if(i<n-1 and !vis[i+1]){
                    vis[i+1]=true;
                    q.push(i+1);
                }
                if(i>0 and !vis[i-1]){
                    vis[i-1]=true;
                    q.push(i-1);
                }
                for(int x:map[nums[i]]){
                    if(x!=i and !vis[x]) {
                        q.push(x);
                        vis[x]=true;
                    }
                    map[nums[i]].clear();
                }
            }
            count++;
        }
        return count;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        //unorder map for element occurence frequency
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n;i++){
            map[nums[i]].push_back(i);
        }
        vector<bool> vis(n,false);
        return bfs(nums,vis,map);
    }
};