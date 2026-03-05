class Solution {
public:
    void rec(vector<int>& nums, vector<int> & subset, int idx, vector<vector<int>>& ans){
        if(idx>=nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]); //include the current digit
        rec(nums,subset,idx+1,ans); // call for next digit for inclusion

        subset.pop_back(); //exclue that included digit 
        rec(nums,subset,idx+1,ans); // call for next digit for exclusion
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        rec(nums,subset,0,ans);
        return ans;
    }
};