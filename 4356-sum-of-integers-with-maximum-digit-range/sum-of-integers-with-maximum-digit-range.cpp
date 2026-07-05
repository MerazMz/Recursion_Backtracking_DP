class Solution {
public:
    int digitRange(int n){
        int largest = 0;
        int smallest = 9;
        while(n>0){
            int ld = n%10;
            largest = max(largest,ld);
            smallest = min(smallest,ld);
            n=n/10;
        }
        return largest-smallest;
    }
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int maxRange=0;
        for(int i=0;i<n;i++){
            maxRange = max(maxRange, digitRange(nums[i]));
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(digitRange(nums[i])==maxRange){
                ans+=nums[i];
            }
        }
        return ans;

    }
};