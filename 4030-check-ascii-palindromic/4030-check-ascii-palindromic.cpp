class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.length();
        string str="";
        for(int i=0;i<n;i++){
            int a=s[i];
            bitset<8> binary(a);
            string temp=binary.to_string();
            str+=temp;
        }

        int i=0,j=str.length()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};