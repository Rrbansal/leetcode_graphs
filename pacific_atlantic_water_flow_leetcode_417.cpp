class Solution {
public:
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
int rows;
int cols;
vector<vector<int>>h;
vector<vector<bool>>bfs(queue<pair<int,int>>&q)
{
    vector<vector<bool>>visited(rows,vector<bool>(cols,false));
    while(!q.empty())
    {
        auto cell=q.front();
        q.pop();
        int i=cell.first;
        int j=cell.second;
        visited[i][j]=true;
        for(int d=0;d<4;d++)
        {
            int newrow=i+dir[d][0];
            int newcol=j+dir[d][1];
            if(newrow<0 || newcol<0 || newrow>=rows || newcol >=cols) continue;
            if(visited[newrow][newcol]) continue;
            if(h[newrow][newcol]< h[i][j]) continue;
            q.push({newrow,newcol});

        }

    }
    return visited;
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        h=heights;
        queue<pair<int,int>>pbfs;
        queue<pair<int,int>>abfs;
        for(int i=0;i<rows;i++)
        {
            pbfs.push({i,0});
            abfs.push({i,cols-1});
        }
        for(int j=1;j<cols;j++)
        {
            pbfs.push({0,j});
        }
        for(int j=0;j<cols;j++)
        {
            abfs.push({rows-1,j});
        }
        vector<vector<bool>>pacific=bfs(pbfs);
        vector<vector<bool>>atlantic=bfs(abfs);
        vector<vector<int>>result;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(pacific[i][j] and atlantic[i][j]) result.push_back({i,j});
            }
        }
        return result;
        
    }
};
