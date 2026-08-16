class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<pair<int,int>>q;

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        if(!fresh) return 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int minutes=0;
            while(!q.empty()){
              int s=q.size();
              bool change=0;
              for(int i=0;i<s;i++){
                  auto [x,y]=q.front();
                  q.pop();
                for(int k=0;k<4;k++){
                    int nr=x+dr[k];
                    int nc=y+dc[k];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                        change=true;
                    }
                }
               }
                if(change) minutes++;
            }
            
    
        if(fresh) return -1;
        return minutes;
    }
};