class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            if(curr=='(' || curr=='{' || curr=='['){
                st.push(curr);
            }else{
                if(st.empty()) return false;
                char tp=st.top();
                if(tp=='(' && curr!=')') return false;
                if(tp=='{' && curr!='}') return false;
                if(tp=='[' && curr!=']') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};