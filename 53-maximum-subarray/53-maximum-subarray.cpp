//using kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& arr) 
    {
        int maxSum = INT_MIN;
        int curSum = 0;
        int max_idx = arr[0];
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            curSum+=arr[i];
            
            if(arr[i] > max_idx)
                max_idx = arr[i];
            
            if(curSum < 0 ){
                curSum = 0 ;
            }
            
            maxSum = max(maxSum , curSum);
        }
    
        if(max_idx>maxSum || maxSum==0){
            return max_idx;
        }
        return maxSum;
    }
};

// i can't initialise maxSum with any value as that would lead to wrong ans 