class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> map;
        int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            map[s[i]]++;
            while(map.count('a') and map.count('b') and map.count('c')){
                count+=n-i;
                map[s[j]]--;
                if(map[s[j]]==0){
                    map.erase(s[j]);
                }
                j++;
            }
        }
        return count;
    }
};