class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]) return -1;

        // queue<pair<int,int>> q;
        queue<vector<int>> q;  //r, c, count
        // vector<vector<bool>> vis(n,vector<bool>(m,false));

        q.push({0,0,1});
        // vis[0][0]=true; 
        grid[0][0]=1;
        vector<pair<int,int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        while(!q.empty()){
            // int r = q.front().first;
            // int c = q.front().second;
            int r = q.front()[0];
            int c = q.front()[1];
            int count = q.front()[2];
            q.pop();

            if(r==n-1 and c==m-1) return count;
            
            for(auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == 0) {

                    grid[nr][nc] = 1;  
                    q.push({nr, nc, count + 1});
                }
            }
        }
        return -1;
    }
};