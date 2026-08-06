class Solution {
public:

    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
        if(vis[node]) return;
        vis[node]=1;
        // exploring neighbors
        for(int i=0;i<isConnected[node].size();i++){
            if(!vis[i] && isConnected[node][i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};