class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        set<char> st;
        for(char c:word){
            st.insert(c);
        }
        int count=0;
        for(char w:word){
            if(isupper(w)) continue;
            if(islower(w) and st.count(toupper(w))){
                count++;
                st.erase(toupper(w));
            }
        }
        return count;

    }
};