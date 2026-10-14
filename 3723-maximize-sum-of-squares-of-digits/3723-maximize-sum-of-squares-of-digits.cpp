class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       string str;

        if(sum>9*num) return "";
        string res=""; 
        for(int i=0;i<num;i++){
            int digit=min(9,sum);
            res+=(char)(digit+'0');
            sum-=digit;
        }
        str=res;
        
        int tSum=sumi(res);
        int scr=squareSum(res);
        
        return res;
    }
private:
    int sumi(const string &num){
    int summ=0;
    for(char c:num) summ+=(c-'0');
    return summ;
    }

    int squareSum(const string &num){
        int sSum=0;
        for(char c:num){
            int d=c-'0';
            sSum+=d*d;
        }
        return sSum;
    }
};