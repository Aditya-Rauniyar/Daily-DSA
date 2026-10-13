class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
            int n=nums.size();
        sort(nums.begin(),nums.end(),[](int n1,int n2){
            return (abs(n1)>abs(n2));
        });

    vector<int> arr;
        int s=0;
        int e=n-1;
        while(s<=e){
            arr.push_back(nums[s]);
            s++;
            if(s<=e) arr.push_back(nums[e--]);
        }
    long long eveSum=0;
            for(int i=0;i<arr.size();i++){
                long long square=1LL*arr[i]*arr[i];
                if(i%2==0) eveSum+=square;
            }
    long long oddSum=0;
            for(int i=0;i<arr.size();i++){
                long long square=1LL*arr[i]*arr[i];
                if(i%2!=0) oddSum+=square;
            }

    return eveSum-oddSum;
    }
};