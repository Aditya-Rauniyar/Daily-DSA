class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<pair<int,int>>q;
    int m,n;
    int ans=0;

    void bfs(int i,int j,vector<vector<int>>& grid){
        int temp=0;
        q.push({i,j});
        grid[i][j] = 0;
        bool reached=false;
        if(i==0 || j==0 || i==m-1 || j==n-1){
            reached=true;
        }
        temp++;

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if((nr==0 || nc==0 || nr==m-1 || nc==n-1) && grid[nr][nc]) reached=true;
                    if(grid[nr][nc]==1){
                        grid[nr][nc]=0;
                        q.push({nr,nc});
                        if(!reached) temp++; 
                    }
                }
            }
        }
        if(!reached) ans+=temp;
    }

    int numEnclaves(vector<vector<int>>& grid) {
       m=grid.size();
       n=grid[0].size(); 
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                  bfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};