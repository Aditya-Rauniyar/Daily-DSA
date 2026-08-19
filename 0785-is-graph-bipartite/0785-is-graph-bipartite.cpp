class Solution {
public:

    int dfs(int node,int color,vector<vector<int>>& graph,vector<int>&vis){
        vis[node]=color;

        for(int a:graph[node]){
            if(vis[a]==color) return false;

            if(vis[a]==-1){
                int nc=1-color;
                vis[a]=nc;
                if(!dfs(a,nc,graph,vis)) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(i,0,graph,vis)) return false;
            }
        }
      return true;
    }
};