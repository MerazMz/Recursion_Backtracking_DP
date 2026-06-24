class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int st = 0, end=n-1,i=0;
        while(i<=end){
            if(nums[i]==0){
                swap(nums[st],nums[i]);
                st++;
                i++;
            }else if(nums[i]==2){
                swap(nums[i],nums[end]);
                end--;
            }else{
                i++;
            }
        }
    }
};