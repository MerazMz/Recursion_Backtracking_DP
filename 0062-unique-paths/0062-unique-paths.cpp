class Solution {
public:
    int backtrack(vector<vector<int>>& grid,int m, int n, int r, int c){
        if(r>=m || c>=n ) return 0;
        if(r==m-1 and c==n-1){
            return 1;
        }
        if(grid[r][c] != -1) return grid[r][c]; // reuse
        grid[r][c] = backtrack(grid,m,n,r+1,c) //down
        + backtrack(grid,m,n,r,c+1);//right
        return grid[r][c];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        return backtrack(grid,m,n,0,0);
    }
};