class Solution {
public:
    int ans=0; //global variable
    void backtrack(vector<vector<int>>& grid, int currsum, int r, int c){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==0) return ;
        
        
        int temp = grid[r][c]; //store cell value for retrival purpose
        currsum += temp;

        ans= max(ans,currsum); //update ans

        grid[r][c]=0; // mark visited
        backtrack(grid ,currsum, r+1,c);
        backtrack(grid ,currsum, r,c+1);
        backtrack(grid ,currsum, r-1,c);
        backtrack(grid ,currsum, r,c-1);
        grid[r][c]=temp; //restore value backtracking step
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    backtrack(grid,0,i,j);
                }
            }
        }
        return ans;
    }
};