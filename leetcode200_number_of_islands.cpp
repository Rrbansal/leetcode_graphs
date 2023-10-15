class Solution {
public:
void dfs(vector<vector<char>>&board,int row,int col,int n,int m)
{
    if(row>=n || col>=m || row<0 || col<0 || board[row][col]!='1') return;

        board[row][col]='0';
       dfs(board,row+1,col,n,m);
       dfs(board,row-1,col,n,m);
        dfs(board,row,col+1,n,m);
       dfs(board,row,col-1,n,m);

}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return count;
        
    }
};
