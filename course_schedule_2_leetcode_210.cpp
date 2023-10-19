class Solution {
public:
vector<list<int>>graph;
queue<int>q;
unordered_set<int>visi;
vector<int>ans;
int v,e;
void add_edge(int a,int b)
{
    graph[a].push_back(b);
}
void topobfs()
{
    vector<int>id(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto nei:graph[i])
        {
            id[nei]++;
        }
    }
    for(int i=0;i<v;i++)
    {
        if(id[i]==0)
        {
            q.push(i);
            visi.insert(i);
        }
    }
    while(! q.empty())
    {
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto nei:graph[node])
        {
            if(not visi.count(nei))
            {
                id[nei]--;
                if(id[nei]==0)
                {
                    q.push(nei);
                    visi.insert(nei);
                }
            }
        }
    }
    
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
             v=numCourses;
         graph.resize(v,list<int>());
        for(int i=0;i<p.size();i++)
        {
            add_edge(p[i][1],p[i][0]);
        }

        topobfs();
        if(ans.size()==v) return ans;
        ans.clear();
       return ans;

        
    }
};
