class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        bool mark=false;
        for(int i=0;i<n;i++){
            if(s[i]=='a' and mark) return false;
            if(s[i]=='b') mark = true;
        }
        return true;
    }
};