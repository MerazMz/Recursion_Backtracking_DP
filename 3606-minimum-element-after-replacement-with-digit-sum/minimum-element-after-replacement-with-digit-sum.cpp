class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int n:nums){
            int sum = 0;
            while(n>0){
                int ld = n%10;
                sum += ld;
                n=n/10;
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};