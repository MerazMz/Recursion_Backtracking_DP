class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            if(i==0){
                rightSum -= nums[i];
                ans[i] = abs(leftSum-rightSum); 
            }
            else if(i>0){
                leftSum += nums[i-1];
                rightSum -= nums[i];
                ans[i] = abs(leftSum-rightSum); 
            }
        }
        return ans;
    }
};