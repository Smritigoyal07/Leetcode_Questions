class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        
        if(n<4 || n%2!=0)
            return false;
        
        while(n>=4){
            if(n%4==0)
                n=n/4;
            else
                return false;
            
            if(n==1 )
                return true;
        }
        
        return false;
    }
};