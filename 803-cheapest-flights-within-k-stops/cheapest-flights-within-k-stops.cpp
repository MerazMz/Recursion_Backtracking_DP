class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);

        vector<pair<int,int>> g[n];

        for(auto e:flights){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            g[u].push_back({v,wt});
        }
        dist[src]=0;

        queue<vector<int>> q;
        // (cost, u, stops);
        q.push({0, src, -1});

        while(!q.empty()){
            int cost = q.front()[0];
            int u = q.front()[1];
            int stop = q.front()[2];
            q.pop();
            for(auto e:g[u]){
                int v = e.first;
                int wt = e.second;
                if(dist[v] > cost + wt and stop+1<=k){
                    dist[v] = cost + wt;
                    q.push({dist[v],v,stop+1});
                }
            }
        }
        return dist[dst]==INT_MAX? -1:dist[dst];
    }
};