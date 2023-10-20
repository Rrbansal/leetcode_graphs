class Solution {
public:
int n;
queue<int>q;
unordered_set<int>visited;
vector<int>result;
void bfs(vector<vector<int>>& board,vector<int>ans)
{
    int count=0;
    while(!q.empty())
    {
        int k=q.size();
        count++;
        for(int i=0;i<k;i++)
        {
            int cell=q.front();
            q.pop();
            for(int i=1;i<=6;i++)
            {
                int nc=cell+i;
                if(ans[nc]==n*n) 
                {
                    result.push_back(count);
                    continue;
                }
                if(ans[nc]>n*n || visited.count(ans[nc])!=0) continue;
                else
                {
                    q.push(ans[nc]);
                    visited.insert(ans[nc]);
                }
            }
        }
        
    }
}
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        vector<int>ans(500,0);
        int flag=0;
        int count=1;
        for(int i=n-1;i>=0;i--)
        {
            if(flag==0)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==-1) ans[count]=count;
                    else ans[count]=board[i][j];
                    count++;
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(board[i][j]==-1) ans[count]=count;
                    else ans[count]=board[i][j];
                    count++;
                }
            }
            if(flag==0) flag=1;
            else flag=0;

        }
        q.push(1);
        visited.insert(1);
        bfs(board,ans);
        if(result.size()==0) return -1;
        sort(result.begin(),result.end());
        return result[0];        
    }
};
