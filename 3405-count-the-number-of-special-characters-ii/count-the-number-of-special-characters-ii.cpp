class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        string temp;
        for(char c:word){
            temp.push_back(tolower(c));
        }
        set<char> st(temp.begin(),temp.end());

        unordered_map<char,pair<int,int>> map;

        for(char c:st){
            int first = word.find(toupper(c));
            int last = word.find_last_of(c);
            map[c]={first,last};
        }
        int count=0;
        for(auto pair:map){
            auto [first,second] = pair.second;
            if(first!=-1 and second!=-1){
                if(first>second) count++;

            }
        }
        return count;


    }
};