class Solution {
public:
    int n;


    int solve(int i,int t,vector<int>&nums,vector<vector<int>>&dp){
        if(t==0) return 0;
        if(i==n) return 1e9;
        if(dp[i][t]!=-1) return dp[i][t];

        int ans=solve(i+1,t,nums,dp);

        long long x=nums[i];
        int cst=0;

        while(x<=t){
            ans=min(ans,cst+solve(i+1,t-x,nums,dp));
            x*=2;
            cst++;
        }

        x=nums[i];
        cst=0;
        
        while(x>0){
            x/=2;
            cst++;

            if(x<=t){
                ans=min(ans,cst+solve(i+1,t-x,nums,dp));
            }
            
        }

        return dp[i][t]=ans;
    }
    
    int minOperations(vector<int>& nums, int sum) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int an=solve(0,sum,nums,dp);
        if(an>=1e9) return -1;
        return an;
        
    }
};