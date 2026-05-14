class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        if(n!=maxi+1) return false;

        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        bool ans=true;
        for(auto& pair:map){
            if(pair.first==maxi and pair.second!=2) ans=false;
            if(pair.first!=maxi and pair.second!=1) ans=false;
        }
        return ans;
    }
};