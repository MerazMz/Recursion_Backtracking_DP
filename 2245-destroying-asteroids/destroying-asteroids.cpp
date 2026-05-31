class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long m=mass;
        // reverse(ast.begin(),ast.end());
        int n=ast.size();
        for(int i=0;i<n;i++){
            if(ast[i]>m) return false;
            else{
                m += ast[i] ;
            }
        }
        return true;
    }
};