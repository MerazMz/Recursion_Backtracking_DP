class Solution {
public:
    int solve(int n){
        int sum = 0;
        while(n>0){
            int ld = n%10;
            sum += ld;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i] = solve(nums[i]);
        }
        return *min_element(nums.begin(),nums.end());
    }
};