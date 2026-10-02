class Solution {
public:

    vector<string>ans;

    bool isvalid(string &s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') count++;
            else{
                count--;
                if(count<0) return false;
            }
        }
        return count==0;
    }

    void solve(int n,vector<string>&ans,string s){
        if(s.length()==2*n){
            if(isvalid(s)){
                ans.push_back(s);
            }
            return;
        }

        s.push_back('(');
        solve(n,ans,s);

        s.pop_back();

        s.push_back(')');
        solve(n,ans,s);

    }


    vector<string> generateParenthesis(int n) {
     string s="";
     solve(n,ans,s);  
     return ans; 
    }
};