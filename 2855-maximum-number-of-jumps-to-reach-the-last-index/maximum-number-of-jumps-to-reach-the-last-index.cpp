class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, vector<int>& dp){
        int n=nums.size();
        if(idx==n-1) return 0;
        if(dp[idx]!=INT_MIN){ //already calculated for that index 
            return dp[idx];
        }
        int result=INT_MIN;
        for(int j=idx+1;j<n;j++){
            if(abs(nums[idx]-nums[j])<=target){
                int temp = 1+solve(nums,target,j,dp);
                result=max(result,temp);
            }
        }
        return dp[idx]=result;

    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n+1,INT_MIN);
        int ans = solve(nums,target,0,dp);
        return ans<0? -1:ans;
    }
};