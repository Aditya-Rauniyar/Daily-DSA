class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int x:nums) st.insert(x);
        int maxi= *max_element(nums.begin(),nums.end());

        int temp=0;
        for(int i=k;i<=maxi+k;i+=k){
            temp+=k;
            if(st.find(temp)==st.end()) return temp;
        }
        return temp;
    }
};