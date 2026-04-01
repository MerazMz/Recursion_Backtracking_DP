class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // int INF = INT_MAX;
        vector<vector<int>> result(n,vector<int>(m,10000));


        //pass 1 traverse the complete grid and mark the minimum pos closest distance from only top and left 
        for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) result[i][j]=0;
                else{
                    if(i>0){
                        result[i][j] = min(result[i][j],result[i-1][j]+1); //top
                    }
                    if(j>0){
                        result[i][j] = min(result[i][j],result[i][j-1]+1); //left
                    }

                }
            }
        }
        //pass 2 traverse the complete grid in reverse manner and mark the minimum pos closest distance from only bottom and right 
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]!=0){
                    if(i<n-1){
                        result[i][j] = min(result[i][j],result[i+1][j]+1);//bottom
                    }
                    if(j<m-1){
                        result[i][j] = min(result[i][j],result[i][j+1]+1); //right
                    }
                }
            }
        }
        return result;
    }
};