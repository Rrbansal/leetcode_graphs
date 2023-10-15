class Solution {
public:
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fo=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) fo++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        q.push({-1,-1});
        int min=0;
        while(!q.empty())
        {
            auto cell=q.front();
            int i=cell.first;
            int j=cell.second;
            q.pop();
            if(i==-1 and j==-1)
            {
               min++;
               if(!q.empty()) q.push({-1,-1});
               else break;
            }
            else
            {
                for(int d=0;d<4;d++)
                {
                    int nr=i+dir[d][0];
                    int nc=j+dir[d][1];
                    if(nr <0 || nc<0 || nr>=n || nc>=m) continue;
                    if(grid[nr][nc]==2 || grid[nr][nc]==0) continue;
                    fo--;
                    grid[nr][nc]=2;
                    q.push({nr,nc}); 
                }
            }
        }
        if(fo==0) return min-1;
        return -1;
    }
};
