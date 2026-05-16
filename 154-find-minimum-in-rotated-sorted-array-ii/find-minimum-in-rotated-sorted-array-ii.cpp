class Solution {
public:
    int findMINI(vector<int>& nums) {
            int n=nums.size();
            int st=0;
            int end=n-1;
            while(st<end){
                int mid = st +(end-st)/2;
                if(nums[mid]<nums[end]){
                    end=mid;
                }else{
                    st=mid+1;
                }
            }
            return nums[st];
        }
    int findMin(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        vector<int> num(st.begin(),st.end());
        return findMINI(num);
    }
};