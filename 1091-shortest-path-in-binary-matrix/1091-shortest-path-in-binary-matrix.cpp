class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1 )
        {
            return -1;
        }
        vector<int> row = {1,-1,0,0,1,-1,1,-1};
        vector<int> col = {0,0,1,-1,1,1,-1,-1};
        
        queue<pair<pair<int,int>,int>> que;
        que.push({{0,0},1});
        
        while(!que.empty())
        {
            pair<pair<int,int>,int> temp;
            temp = que.front();
            int x = temp.first.first;
            int y = temp.first.second;
            int z = temp.second;
            
            if(x==n-1 && y==n-1)
                return z;
            
            for(int i = 0 ; i < 8 ;i++)
            {
                int r = x+row[i] ;
                int c = y+col[i] ;
                
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0){
                    grid[r][c] = 1;
                    que.push({{r,c},z+1});
                }
            }
            
            que.pop();
        }
         return -1;
    }
   
};

