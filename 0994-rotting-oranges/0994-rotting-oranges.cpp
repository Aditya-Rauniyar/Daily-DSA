class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }

        if(!fresh) return 0;
        int minutes=0;

        vector<vector<int>>vis(m,vector<int>(n,0));

        while(!q.empty() && fresh>0){
            int size=q.size();

            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                     if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;  
                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }

        if(fresh>0) return -1;
        return minutes;

    }
};