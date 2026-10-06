class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[i]==')'){
                st.pop();
                cnt+=2;
            }
            if(s[i]=='('){
                st.push(s[i]);
            }
        }
        int openSize=st.size();
        int closeSize=s.length()-cnt-openSize;
        return openSize+closeSize;
    }
};