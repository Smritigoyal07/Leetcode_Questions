class Solution {
public:
    void bfs(vector<vector<int>>& grid,int i,int j , int &area)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
        {
            return;
        }
        
        grid[i][j]=-1;
        bfs(grid,i+1,j, area);
        bfs(grid,i,j+1, area);
        bfs(grid,i-1,j, area);
        bfs(grid,i,j-1, area);
        
        area++;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int MaxArea = 0;
        
        for(int i=0 ; i<grid.size() ; i++)
        {
            for(int j=0 ; j<grid[0].size() ; j++)
            {
                int area = 0;
                
                if(grid[i][j]==1)
                {
                   bfs(grid,i,j,area);
                }
                
                if(area > MaxArea)
                    MaxArea = area; 
            }
        }
        
        return MaxArea;
    }
    
    
};