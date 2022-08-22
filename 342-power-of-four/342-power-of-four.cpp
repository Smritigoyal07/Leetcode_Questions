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

// basically you need to check 5 conditions 

//1. 4^0 = 1 so return T for 1
//2. 4^1 = 4 so cant be less than 4
//3. 4^2 = 16 all even numbers only 
//4. check for no. that are even bt not dicisible by 4 return F
//5. if on repeated divison n becomes 1 return true else false;