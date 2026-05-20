class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<int> ans(n);
        vector<int> freq(n+1);
        for(int i=0;i<n;i++){
            int count=0;
            freq[a[i]]++;
            freq[b[i]]++;
            for(int j=0;j<freq.size();j++){
                if(freq[j]>=2) count++;
            }
            ans[i]=count;

        }
        return ans;
    }
};