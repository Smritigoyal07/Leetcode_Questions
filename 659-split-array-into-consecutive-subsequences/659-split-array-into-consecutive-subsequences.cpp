class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        
        map<int,int> mp;
        
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        
        int count = n;
        
        for(int i = 0 ; i < n ; i++){
            int x = nums[i];
            
            //if all 3 consecutive number are present then reduce their count 
            
            if(mp[x] && mp[x+1] && mp[x+2]){
                mp[x]--;
                mp[x+1]--;
                mp[x+2]--;
                x +=3;
                count -= 3;
                
                // this condition to check their can be longer consecutive subsequence than 3 
                // also mp[x] > mp[x-1] checks that there should be more than 1 count of that number in map 
                
                while(mp[x] > 0 and mp[x] > mp[x-1]){
                    count--;
                    mp[x]--;
                    x++;
                }
            }          
        }
        
        if(count==0){
            return true;
        }
        
        return false;
    }
};