class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> diff(2*limit+2,0);

        for(int i=0;i<n/2;i++){
            int a = nums[i];
            int b = nums[n-1-i];
            int minval = min(a,b)+1;
            int maxval = max(a,b)+limit;
            //difference array technique
            //fill 2 entirely
            diff[2] += 2;
            diff[2*limit+1] -= 2;
            
            // for move 1 decrese the count by 1 ie 2-1=1
            diff[minval] += (-1);
            diff[maxval+1] -= (-1);

            // for move 0 decrese more by 1 to make 0
            diff[a+b] += (-1);
            diff[a+b+1] -= (-1);
        }
        int ans = INT_MAX;

        for(int sum=2; sum<=2*limit; sum++){
            diff[sum] += diff[sum-1]; 
            ans = min(ans,diff[sum]);
        }
        return ans;

    }
};