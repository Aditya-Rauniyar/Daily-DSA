class Solution {
public:

    bool dfs(int i,vector<vector<int>>& graph,vector<int>&vis,
        vector<int>&pathVis,
        vector<int>&check)
    {
        if(vis[i] && pathVis[i]) return true;
        if(vis[i]) return false;
        vis[i]=1;
        pathVis[i]=1;

        for(int a:graph[i]){
            if(!vis[a]){
                if(dfs(a,graph,vis,pathVis,check)) return true;
            }else if(pathVis[a]) return true;
        }

        pathVis[i]=0;
        check[i]=1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>check(n,0);
        vector<int>pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,check);
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(check[i]) ans.push_back(i);
        }

        return ans;
    }
};