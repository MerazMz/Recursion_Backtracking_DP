class Solution {
public:
    int largestAltitude(vector<int>& nums) {
        int n=nums.size();
        int maxi = 0;
        int gain=0;
        for(int i=0;i<n;i++){
            int gain = gain+nums[i];
            maxi = max(maxi,gain);
        }
        return maxi;
    }
};