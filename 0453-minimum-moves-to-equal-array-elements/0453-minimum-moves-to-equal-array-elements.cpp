class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int mini=nums[0];
        for(int i=n-1;i>=0;i--){
            // if(mp.count(nums[i])<1){
                count+=abs((mini-nums[i]));
            // }
            //     mp[nums[i]]++; 
        }
        return count;
    }
};