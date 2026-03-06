class Solution {
public:
    void rec(vector<int>& nums,vector<int>& subset, vector<vector<int>>& ans, int target, int idx){
        int n=nums.size();
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(idx==n or target<0){
            return;
        }
        subset.push_back(nums[idx]);
        rec(nums,subset,ans,target-nums[idx],idx+1);
        subset.pop_back();
        
        int skip = idx+1; // next index for exclusion call 
        while(skip<nums.size() and nums[skip]==nums[skip-1]){ // skip the duplicate
            skip++;
        }
        rec(nums,subset,ans,target,skip);

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        rec(nums,subset,ans,target,0);
        return ans;
    }
};