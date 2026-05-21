class Solution {
public:
    void findprefix(string s,unordered_set<int>& st){
        int n=s.size();
        for(int i=0;i<1;i++){
            for(int j=i;j<n;j++){
                string sub = s.substr(i,j-i+1);
                st.insert(stoi(sub));
            }
        }
    }
    int longestCommonPrefix(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_set<int> st;
        for(int num:nums1){
            findprefix(to_string(num),st);
        }
        int ans=0;
        for(int num:nums2){
            int size = to_string(num).size();
            while(num>0){
                if(st.count(num)){
                    ans=max(ans,size);
                }
                num=num/10;
                size--;
            }
        }
        return ans;
        
    }
};