class Solution {
public:
    bool backtrack(vector<int>& nums,vector<bool>& used, int k, int target, int idx, int subsetSum){
        if (k == 1) return true;
        if(k==0)    return true;
        if(subsetSum==target){
            return backtrack(nums,used,k-1,target,0,0); //reset subset sum and index to start from new
        }
        for(int i=idx;i<nums.size();i++){
            if(used[i] or subsetSum+nums[i]>target){
                continue;
            }
            used[i]=true;
            if(backtrack(nums,used,k,target,i+1,subsetSum+nums[i])){
                return true;
            }
            used[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        vector<bool> valid (nums.size(),false);
        sort(nums.rbegin(), nums.rend()); 
        return backtrack(nums,valid,k,target,0,0);
        
    }
};