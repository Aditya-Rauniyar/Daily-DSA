class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count=0;
        vector<int>temp(101,0);
        
        for(int i=0;i<nums.size();i++){
            if(i==0||nums[i]!=nums[i-1]){
             temp[nums[i]]++;   
            }
        }

        for(int i=1;i<=100;i++){
            if(temp[i]==1) count++;
        }

        return count;
    }
};