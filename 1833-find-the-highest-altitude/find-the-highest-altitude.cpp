class Solution {
public:
    int largestAltitude(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        ans.push_back(0);
        int maxi = INT_MIN;
        int gain=0;
        for(int i=0;i<n;i++){
            gain = gain+nums[i];
            ans.push_back(gain);
        }
        // for(int x:ans){
        //     cout<<x<<" ";
        // }
        return *max_element(ans.begin(),ans.end());
    }
};