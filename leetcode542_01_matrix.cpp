class Solution {
public:
queue<pair<int,int>>q;
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j]=0;
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
                    if(nr<0 || nc<0 || nr>=n || nc>=m || ans[nr][nc]!=-1) continue;
                    ans[nr][nc]=count;
                    q.push({nr,nc});
                }

            }

        }
        return ans;
        
    }
};
