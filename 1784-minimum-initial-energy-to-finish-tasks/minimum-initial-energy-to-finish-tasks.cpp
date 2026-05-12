class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid){
        for(auto &nums:tasks){
            int required = nums[0];
            int minimum = nums[1];
            if(mid<minimum) return false;
            else{
                mid = mid - required;
            }
        }
        return true;

    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int st = 0;
        int end = 1e9;
        int ans=INT_MAX;
        sort(tasks.begin(),tasks.end(),[](vector<int> &task1, vector<int> &task2){
            int diff1 =  task1[1]-task1[0];
            int diff2 =  task2[1]-task2[0];
            return diff1>diff2;
        });
        while(st<=end){
            int mid = st+(end-st)/2;

            if(isPossible(tasks,mid)){
                end=mid-1;
                ans=mid;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};