class Solution {
public:
    int solve(vector<int>& nums, int idx, int d, vector<int>& dp){
        if(dp[idx]!=-1) return dp[idx];
        
        int n=nums.size();
        int best = 1;

        //forward
        for(int i=idx+1; i<=min(n-1,idx+d); i++){
            if(nums[i]>=nums[idx]) break;
            best = max(best,1+solve(nums,i,d,dp));
        }

        // backward
        for(int i=idx-1;i>=max(0,idx-d);i--){
            if(nums[i]>=nums[idx]) break;
            best = max(best,1+solve(nums,i,d,dp));
        }
        return dp[idx]=best;
    }
    int maxJumps(vector<int>& nums, int d) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans = max (ans,solve(nums,i,d,dp));
        }
        return ans;
    }
};