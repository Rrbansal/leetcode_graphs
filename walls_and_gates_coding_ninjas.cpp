#include <bits/stdc++.h> 
queue<pair<int,int>>q;
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>>ans;
vector<vector<int>>v;
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

            if(a[i][j]==0) 
            {
                q.push({i,j});
            }
        }
    }
    int count=0;
    while(!q.empty())
    {
        int k=q.size();
        count++;
        for(int c=0;c<k;c++)
        {
            auto cell=q.front();
            int i=cell.first;
            int j=cell.second;
            q.pop();
            for(int d=0;d<4;d++)
            {
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];
                if(nr<0 || nc<0 || nr>=n || nc>=m || a[nr][nc]!=2147483647) continue;
                a[nr][nc]=count;
                q.push({nr,nc});
            }
        }
    }

    return a;

}
