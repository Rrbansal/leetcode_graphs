class Solution {
public:
vector<pair<int,int>>result;
void dfs(vector<vector<int>>& grid, int r, int c, int nc,int oc)
{
    if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!=oc) return ;
    grid[r][c]=-nc;
    dfs(grid,r+1,c,nc,oc);
    dfs(grid,r-1,c,nc,oc);
    dfs(grid,r,c+1,nc,oc);
    dfs(grid,r,c-1,nc,oc);

 if(not(r==0 || c==0 || r==grid.size()-1 || c==grid[0].size()-1 || grid[r+1][c]!=-nc || grid[r-1][c]!=-nc || grid[r][c-1]!=-nc || grid[r][c+1]!=-nc))
    {
        result.push_back({r,c});
    }

}
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
       int oc = grid[row][col];
        if(oc == color) return grid;
        dfs(grid, row, col, color, oc);
        for(auto p : result) {
            int i = p.first;
            int j = p.second;
            grid[i][j] = oc;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] < 0) grid[i][j]*=-1;
            }
        }
        return grid;
    }
};
