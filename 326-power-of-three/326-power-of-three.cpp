class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        
        if(n<3 || n%2==0)
            return false;
        
        while(n>=3){
            if(n%3==0)
                n=n/3;
            else
                return false;
            
            if(n==1)
                return true;           
        }
        
        return false;
        
    }
};