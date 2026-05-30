class Edge{
public:
    int v;
    int wt;
    Edge(int v, int wt){
        this->v=v;
        this->wt=wt;
    }
};

class Solution {
public:
    void dijkstra(int n,int src, vector<vector<Edge>>& graph, int d, vector<vector<int>>& spm){

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        spm[src][src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(dis > spm[src][u]) continue;
            for(Edge e:graph[u]){
                if(spm[src][e.v]> spm[src][u]+e.wt){
                    spm[src][e.v] = spm[src][u]+e.wt;
                    pq.push({spm[src][e.v],e.v});
                }
            }

        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<Edge>> graph(n);

        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            graph[u].push_back(Edge(v,wt));
            graph[v].push_back(Edge(u,wt));
        }
        vector<vector<int>> spm(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            dijkstra(n,i,graph,distanceThreshold,spm);
        }

        vector<int> dist(n);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i != j && spm[i][j] <= distanceThreshold) count++;
            }
            dist[i]=count;
        }

        int mini = INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++){
            if(dist[i]<=mini){
                mini=dist[i];
                ans=i;
            }
        }
        return ans;
        



    }
};