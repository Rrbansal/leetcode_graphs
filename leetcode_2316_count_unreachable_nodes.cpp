class Solution {
public:
vector<list<int>>graph;
vector<int>ans;
vector<int>ans1;
void add_edge(int src,int dst,bool bir=true)
{
    graph[src].push_back(dst);
    if(bir) graph[dst].push_back(src);
}
void dfs(int node ,unordered_set<int>&visited)
{
    visited.insert(node);
    for(auto nei:graph[node])
    {
        if(not visited.count(nei)) dfs(nei,visited);
    }
}
void cc(int v)
{
    int result=0;
    unordered_set<int>visited;
    for(int i=0;i<v;i++)
    {
        if(visited.count(i)==0)
        {
            dfs(i,visited);
            ans.push_back(visited.size());
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.resize(n,list<int>());
        for(int i=0;i<edges.size();i++)
        {
            add_edge(edges[i][0],edges[i][1]);
        }
        cc(n);
        long long sum=0,f=0;
        ans1.push_back(ans[0]);
        for(int i=1;i<ans.size();i++) ans1.push_back(ans[i]-ans[i-1]);
        for(int i=1;i<ans.size();i++)  sum+=ans1[i];
        for(int i=0;i<ans1.size()-1;i++)
        {
            f+=ans1[i]*sum;
            sum=sum-ans1[i+1];
        }
        return f;
    }
};

