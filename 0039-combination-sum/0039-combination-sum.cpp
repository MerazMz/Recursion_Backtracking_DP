class Solution {
public:
    void rec(vector<int>& nums,vector<int>& subset, vector<vector<int>>& ans, int target, int idx){
        int n=nums.size();
        if(idx==n or target<0){ //agar out of index hua ya sum target se zayda hua to glt combination hai bhago
            return;
        }
        if(target==0){
            ans.push_back(subset); //agar sum barabar hogya to ek wo possible ans hai
            return;
        }
        subset.push_back(nums[idx]); // har index pr chose and stay kro 
        rec(nums,subset,ans,target-nums[idx],idx); //staying on same index

        subset.pop_back(); // backtrack -> skip and move forward
        rec(nums,subset,ans,target,idx+1); //moving that index
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        rec(candidates,subset,ans,target,0);
        return ans;
    }
};