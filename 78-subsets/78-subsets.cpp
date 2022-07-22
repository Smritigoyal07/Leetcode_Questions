class Solution {
public:
    vector<vector<int>> res;
    
    void add(int i, vector<int> subset,vector<int>& nums ){
        if(i>=nums.size()){
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        add(i+1,subset,nums);
        
        subset.pop_back();
        add(i+1,subset,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        
        add(0,subset,nums);
        
        return res;
    }
};