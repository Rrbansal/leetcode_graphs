class Solution {
public:
map<pair<int,int>,pair<int,int>>m;
queue<pair<int,int>>q;
set<pair<int,int>>s;
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
int r,c;
bool bfs(vector<vector<char>>& grid,pair<int,int>p)
{
    q.push(p);
    s.insert(p);
    while(!q.empty())
    {
        auto cell=q.front();
        int x=cell.first;
        int y=cell.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nr=x+dir[i][0];
            int nc=y+dir[i][1];
            if(nr<0 || nc<0 || nr>=r || nc>=c || grid[nr][nc]!=grid[x][y])  continue;
            pair<int,int>pp={nr,nc};
            if(s.count(pp)!=0 && m[{x,y}]!=pp)  return true;
            if(s.count(pp)!=0 && m[{x,y}]==pp) continue;
            m[{nr,nc}]={x,y};
            s.insert({nr,nc});
            q.push({nr,nc});
        }
    }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        r=grid.size();
        c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                pair<int,int>p={i,j};
                if(s.count(p)==0)
                {
                    bool b=bfs(grid,{i,j});
                    if(b==true) return true;
                }
            }
        }
        return false;
       
    }
};
