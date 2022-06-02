class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int Maxx = 0;
        int count = 0;

        for(int i = 0 ; i < arr.size() ; i++)
        {     
                if(arr[i] == 0)
                    count = 0 ;
                else
                    count++;

                Maxx = max(Maxx,count);
        }
            return Maxx;
        
    }
};