class Solution {
public:
    void  Subsets( vector<vector<int>> &ans, int idx , vector<int>&temp , int target , vector<int>& candidates ){
        if( idx == candidates.size())
        {
            if(target==0)
                ans.push_back(temp);
            
            return ; 
        }
        
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            Subsets(ans, idx , temp,target-candidates[idx],candidates);
            temp.pop_back();
        }          
        
        Subsets(ans, idx+1 , temp , target ,candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        
        Subsets(ans, 0 , temp , target ,candidates );
        
        return ans;
        
    }
};