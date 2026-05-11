class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int num:nums){
            if(num>9){
                string str = "";
                while(num>0){
                    int ld = num%10;
                    str.push_back(ld);
                    num /= 10;
                }
                reverse(str.begin(),str.end());
                for(char c: str){
                    ans.push_back(c);
                }
            }else{
                ans.push_back(num);
            }
        }
        return ans;
    }
};