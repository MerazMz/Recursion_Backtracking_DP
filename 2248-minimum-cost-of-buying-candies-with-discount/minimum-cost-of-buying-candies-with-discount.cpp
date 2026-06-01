class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            if(i%3==2) continue;
            sum += nums[i];
        }
        return sum;
        
    }
};