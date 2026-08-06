class Solution {
public:

    queue<int>q;

    // void dfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
    //     if(vis[node]) return;
    //     vis[node]=1;
    //     // exploring neighbors
    //     for(int i=0;i<isConnected[node].size();i++){
    //         if(!vis[i] && isConnected[node][i]){
    //             dfs(i,isConnected,vis);
    //         }
    //     }
    // }
    
    void bfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[node]=1;
        q.push(node);

        while(!q.empty()){
            int x=q.front();
            q.pop();

            for(int i=0;i<isConnected[x].size();i++){
                if(!vis[i] && isConnected[x][i]){
                    vis[i]=1;
                    q.push(i);
                }
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
                bfs(i,isConnected,vis);
                //dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};