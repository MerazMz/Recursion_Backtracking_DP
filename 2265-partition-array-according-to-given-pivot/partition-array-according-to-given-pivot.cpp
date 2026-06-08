class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> left;
        vector<int> right;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                left.push_back(nums[i]);
            }else if(nums[i]>pivot){
                right.push_back(nums[i]);
            }else{
                count++;
            }
        }
        while(count--){
            left.push_back(pivot);
        }
        for(int num:right){
            left.push_back(num);
        }
        return left;

    }
};