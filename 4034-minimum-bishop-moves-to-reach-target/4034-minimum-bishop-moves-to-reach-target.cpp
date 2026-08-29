class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int ssum=source[0]+source[1];
        int tsum=target[0]+target[1];
        

        if(ssum%2==tsum%2){
            //
            int dx=abs(source[0]-target[0]);
            int dy=abs(source[1]-target[1]);

            if(dx==dy) return 1;
            else return 2;

        }
        

        return -1;
    }
};