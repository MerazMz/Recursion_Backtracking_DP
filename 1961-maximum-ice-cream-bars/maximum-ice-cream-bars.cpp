class Solution {
public:
    int maxIceCream(vector<int>& nums, int coins) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // 1 1 2 3 4 
        int count=0;
        for(int i=0;i<n;i++){
            coins -= nums[i];
            if(coins>=0) count++;
            if(coins<=0) return count;
        }
        return n;
    }
};

