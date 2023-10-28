class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        int dis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dis[i][j]=INT_MAX;
            }
        }
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        dis[0][0]=0;
        while(!dq.empty())
        {
            auto curr=dq.front();
            dq.pop_front();
            int x=curr.first;
            int y=curr.second;
            int dir=grid[x][y];

            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                int ew=1;
                if(i+1==dir) ew=0;

                if(nx<n and ny<m and nx>=0 and ny>=0 )
                {
                    if(dis[nx][ny]>dis[x][y]+ew)
                    {
                        dis[nx][ny]=dis[x][y]+ew;
                        if(ew==1)
                        {
                            dq.push_back({nx,ny});
                        }else
                        {
                            dq.push_front({nx,ny});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];

        
    }
};
