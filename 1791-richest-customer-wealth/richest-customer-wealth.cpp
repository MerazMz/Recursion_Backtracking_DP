class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxSum=INT_MIN;
        for(int i=0;i<accounts.size();i++){
            int s=0;
            for(int j=0;j<accounts[0].size();j++){
                s+=accounts[i][j];
            }
            maxSum=max(maxSum,s);
        }
        return maxSum;
    }
};