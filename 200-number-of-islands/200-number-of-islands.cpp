class Solution {
public:
    
    void bfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1')
        {
            return;
        }
        
        grid[i][j]='S';
        bfs(grid,i+1,j);
        bfs(grid,i,j+1);
        bfs(grid,i-1,j);
        bfs(grid,i,j-1);
        
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int ans=0;
        
        for(int i=0 ; i<grid.size() ; i++)
        {
            for(int j=0 ; j<grid[0].size() ; j++)
            {
                if(grid[i][j]=='1')
                {
                   bfs(grid,i,j);
                   ans++;
                }
            }
        }
        
        return ans;
        // Code here
        
    }
};