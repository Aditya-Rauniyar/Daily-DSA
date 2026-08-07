class Solution {
public:
    // up right down left
    int dr[4]= {-1,0,1,0};
    int dc[4]= {0,1,0,-1};
    int m;
    int n;

    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){
        if(vis[i][j]) return;
        vis[i][j]=1;

        //explore neighbors
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if((nr>=0 && nr<m && nc>=0 && nc<n) && grid[nr][nc]=='1'){ 
                dfs(nr,nc,grid,vis);
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!(vis[i][j]) && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};