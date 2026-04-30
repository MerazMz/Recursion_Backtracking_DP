class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || c<0 || r>=n || c>=m or grid[r][c]!='O'){
            return;
        }
        grid[r][c]='#';
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);

    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){ 
            dfs(grid,i,0);
            dfs(grid,i,m-1);
        }
        for(int i=0;i<m;i++){
            dfs(grid,0,i);
            dfs(grid,n-1,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='#'){
                    grid[i][j]='O';
                }
            }
        }

        
    }
};