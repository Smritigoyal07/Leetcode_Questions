class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int size = tokens.size();
        sort(tokens.begin(),tokens.end());
        
        int score = 0, ans= 0, i = 0, j = size-1;
        
        while(i<=j){
            if(tokens[i]<=power){
                power -= tokens[i];
                score++;
                i++;
                ans=max(ans,score);
            } 
            else if(score>0){
                power += tokens[j];
                score--;
                j--;
            }
            else{
                break;
            }
            
            
        }
        
        return ans;
        
    }
};