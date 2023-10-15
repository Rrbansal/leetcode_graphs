int Solution::knight(int a, int b, int c, int d, int e, int f) {
    if(c==e && d==f) return 0;
    vector<vector<int>>visited(505,vector<int>(505,0));
    queue<pair<int,int>>q;
    vector<int>ans;
    vector<vector<int>>dir={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    q.push({c-1,d-1});
    visited[c-1][d-1]=1;
    int count=0;
    while(!q.empty())
    {
        int k=q.size();
        count++;
        for(int c=0;c<k;c++)
        {
            auto cell=q.front();
            q.pop();
            int i=cell.first;
            int j=cell.second;
            for(int d=0;d<8;d++)
            {
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];
                if(nr<0 || nc<0 || nr>=a || nc>=b || visited[nr][nc]!=0) continue;
                if(nr==e-1 && nc==f-1) ans.push_back(count);
                else
                {
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
            
        }
    }
    if(ans.size()==0) return -1;
    sort(ans.begin(),ans.end());
    return ans[0];
}
