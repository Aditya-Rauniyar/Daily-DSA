class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int>st;
        int n=nums.size();
       
        for(int i=0;i<n;i++) st.insert(nums[i]);
        vector<vector<int>>ans;
        vector<int>temp(2,-1);
        int t2=-1;
        for(int i=lower;i<=upper;i++){
            if(st.find(i)==st.end()){
                if(temp[0]==-1) temp[0]=i;
             t2=i;
            }else{
                if(temp[0]!=-1){
                temp[1]=t2;
                ans.push_back(temp);
                temp[0]=-1;
                temp[1]=-1;
                t2=-1;
                }
            }
        }

        if(temp[0] != -1) {
            temp[1] = t2;
            ans.push_back(temp);
        }

        return ans;
    }
};