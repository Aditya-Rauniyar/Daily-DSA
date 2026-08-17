class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        int s=edges.size();

        for(int i=0;i<s;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        queue<int>q;
        q.push(source);
        vector<int>vis(n,0);
        vis[source]=1;
        if(source==destination) return true;

        bool find=false;
        while(!q.empty()){
            int x=q.front();
            q.pop();

            vector<int>arr=mp[x];
            
            for(int x:arr){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                    if(x==destination){
                      return true;
                    }
                }
            }
            
        }
        return false;
    }
};