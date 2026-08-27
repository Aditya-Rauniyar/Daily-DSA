class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        unordered_map<int,vector<int>>mp;
        vector<int>indgr(V,0);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            mp[u].push_back(v);
            indgr[v]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indgr[i]==0) q.push(i);
        }
        vector<int>ans;

        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);

            for(int a:mp[x]){
                indgr[a]--;
                if(indgr[a]==0) q.push(a);
            }
        }
        if(ans.size()==V) return ans;
        return {};

    }
};