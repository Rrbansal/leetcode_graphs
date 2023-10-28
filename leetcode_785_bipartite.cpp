class Solution {
public:
queue<int>q;
vector<int>color;
int n;
bool bfs(int src,vector<vector<int>>& graph)
{
        q.push(src);
        color[src]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto nei:graph[curr])
            {
                if(color[nei]==-1)
                {
                     color[nei]=!color[curr];
                     q.push(nei);
                } 
                else if(color[curr]==color[nei]) return false;
            }
        }
        return true;

}
    bool isBipartite(vector<vector<int>>& graph) {
         n=graph.size();
        color.resize(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,graph)==false) return false;
            }
        }
       return true;
        
    }
};
