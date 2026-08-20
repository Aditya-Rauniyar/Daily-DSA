class Solution {
public:

    int bfs(int node,vector<vector<int>>& graph,vector<int>&vis){
        int color=0;
       vis[node]=color;
       queue<pair<int,int>>q;
       q.push({node,0});

       while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int a:graph[x]){
            if(vis[a]==-1){
                vis[a]=1-y;
                q.push({a,1-y});
            }else if(vis[a]==y) return false;
        }
       }

        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!bfs(i,graph,vis)) return false;
            }
        }
      return true;
    }
};