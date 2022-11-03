class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int arr[26][26]={};
        int length = 0;
        
        for(auto w : words){
            int i = w[0] - 'a';
            int j = w[1] - 'a'; 
            
            if(arr[j][i]){
                length+=4;
                arr[j][i]--;
            }
            else{
                arr[i][j]++;
            }
        }
                
        for (int i = 0 ; i < 26 ; i++){
            if(arr[i][i]){
                length+=2;
                break;
            }
        }
        
        return length;
        
    }
};