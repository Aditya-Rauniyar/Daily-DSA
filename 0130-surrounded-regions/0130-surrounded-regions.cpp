class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<pair<int,int>>q;
    int m,n;
    int ans=0;

    void bfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis){
       

        vis[i][j]=-1;
        q.push({i,j});

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && vis[nr][nc]==0){
                    vis[nr][nc]=-1;
                    q.push({nr,nc});
                }

            }
        }
    }

    void solve(vector<vector<char>>& board) {
       m=board.size();
       n=board[0].size(); 
       
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X') vis[i][j]=-1;
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O') bfs(0,j,board,vis);
        }

        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O') bfs(i,n-1,board,vis);
        }

        for(int j=n-1;j>=0;j--){
           if(board[m-1][j]=='O')  bfs(m-1,j,board,vis);
        }

        for(int i=m-1;i>=0;i--){
           if(board[i][0]=='O') bfs(i,0,board,vis);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0) board[i][j]='X';
            }
        }

    }
};