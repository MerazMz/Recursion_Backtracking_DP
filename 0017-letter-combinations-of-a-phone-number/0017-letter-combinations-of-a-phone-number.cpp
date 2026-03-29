class Solution {
public:
    vector<string> phone= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

    void backtrack(string str, int idx, vector<string>& ans, string curr){
        if(idx == str.size()){
            ans.push_back(curr);
            return;
        }
        int digit = str[idx]-'0';
        string s = phone[digit];

        for(char c:s){
            backtrack(str,idx+1,ans,curr+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        backtrack(digits,0,ans,"");
        return ans;
    }
};