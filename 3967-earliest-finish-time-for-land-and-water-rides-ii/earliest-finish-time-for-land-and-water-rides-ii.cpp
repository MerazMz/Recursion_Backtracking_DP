class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans = INT_MAX;
        int bestLandRides = INT_MAX;
        int bestWaterRides = INT_MAX;
        //for land
        for(int i=0;i<n;i++){
            bestLandRides = min(bestLandRides, landStartTime[i]+landDuration[i]);
        }

        for(int i=0;i<m;i++){
            int waterStart = max(waterStartTime[i],bestLandRides);
            int waterFinish = waterStart + waterDuration[i];
            ans = min(ans,waterFinish);
        }
        //for water
        for(int i=0;i<m;i++){
            bestWaterRides = min(bestWaterRides, waterStartTime[i]+waterDuration[i]);
        }

        for(int i=0;i<n;i++){
            int landStart = max(landStartTime[i],bestWaterRides);
            int landFinish = landStart + landDuration[i];
            ans = min(ans,landFinish);
        }
        return ans;

        
    }
};