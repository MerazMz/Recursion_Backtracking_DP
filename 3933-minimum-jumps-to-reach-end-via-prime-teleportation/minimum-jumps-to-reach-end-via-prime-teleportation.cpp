class Solution {
public:
    vector<bool> isPrime;
    void seive(int n) {
        isPrime.resize(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j=j+i){
                    isPrime[j]=false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> map;
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            map[nums[i]].push_back(i);
        }
        seive(maxi);
        queue<int>q;
        vector<bool>vis(n);
        q.push(0);
        vis[0]=true;
        set<int> seen;
        int steps=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front();
                q.pop();
                if(i== n-1) return steps;
                if(i-1>0 and !vis[i-1]){
                     q.push(i-1);//adjacent 
                     vis[i-1]=true;
                }
                if(i+1<n and !vis[i+1]){
                     q.push(i+1);//adjacent
                     vis[i+1]=true;
                }
                if(!isPrime[nums[i]] || seen.count(nums[i])) continue;

                if(isPrime[nums[i]]){
                    for(int multi=nums[i];multi<=maxi;multi+=nums[i]){
                        if(map.count(multi)){
                            vector<int> idx=map[multi];
                            for(int x:idx){
                                if(!vis[x]){
                                    q.push(x);
                                    vis[x]=true;
                                }
                            }
                        }

                    }
                    seen.insert(nums[i]);

                }
            }
            steps++;
        }
        return steps;

    }
};