class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<pair<int,int>>q;
    int m,n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=-1;
                }
            }
        }

        while(!q.empty()){
                auto[x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=x+dr[k];
                    int nc=y+dc[k];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        if(mat[nr][nc]==-1){
                            mat[nr][nc] = 0;
                            ans[nr][nc]=ans[x][y]+1;
                            q.push({nr,nc});
                        }
                    }
                }
        }
        return ans;
    }
};