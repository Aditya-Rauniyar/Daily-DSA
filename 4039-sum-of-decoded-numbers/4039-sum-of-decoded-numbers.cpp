class Solution {
public:
    
    long long m=1e9+7;

    long long power(long long x,long long y){
        long long ans=1;
        while(y){
            if(y&1) ans=(ans*x)%m;

            x=(x*x)%m;
            y/=2;
        }
        return ans;
    }
    
    int sumDecoded(vector<long long>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int wi=nums[i]%10;
            string t=to_string(nums[i]/10);

            long long x=stoll(t.substr(0,wi));
            long long y=stoll(t.substr(wi));
            long long p=power(x,y);
            ans=(ans+p)%m;
        }

        return ans;
    }
};