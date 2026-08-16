class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<pair<int,int>>q;
    int m,n;


    int bfs(int i,int j,vector<vector<int>>& grid){
        int count=1;
        q.push({i,j});
        grid[i][j] = 0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(grid[nr][nc]==1){
                        grid[nr][nc]=0;
                        q.push({nr,nc});
                        count++;
                    }
                }
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                  int temp = bfs(i,j,grid);
                  ans=max(ans,temp);
                }
            }
        }

        return ans;
    }
};