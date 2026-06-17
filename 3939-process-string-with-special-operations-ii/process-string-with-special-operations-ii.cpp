class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long L=0;
        //find the final L of the result
        for(char& c:s){
            if(c=='*'){
                if(L>0) L--; //last element get removed so l--;
            }else if(c=='#'){
                L=L*2; //whole string gets doubled
            }else if(c=='%'){
                continue;//no change in L because reverse dont affect the length
            }else{ //normal alphabet in lowercase 
                L++;
            }
        }
        if(k>=L) return '.'; //out of bound condition 

        //kind of backtracking going in reverse
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*'){
                L++; 
            }else if(s[i]=='%'){
                k=L-k-1;
            }else if (s[i]=='#'){
                L=L/2;
                k = (k>=L)? k-L : k;
            }else{
                L--;
            }
            if(k==L) return s[i];
        }
        return '.';
    }
};