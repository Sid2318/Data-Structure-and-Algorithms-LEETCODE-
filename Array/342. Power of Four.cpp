class Solution {
public:
    bool isPowerOfFour(int n) {
        int p =0;
        for(int i=0;i<=15;i++){
            p = pow(4,i);
            if(p==n){
                return true;
            }
            if(p>n){
                return false;
            }
        }
        return false;
    }
};
