// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
void add_edge(int src,int dst,bool bir=true)
{
    graph[src].push_back(dst);
    if(bir)
    {
        graph[dst].push_back(src);
    }
}
void dfs(int node ,unordered_set<int>&visited)
{
    visited.insert(node);
    for(auto nei:graph[node])
    {
        if(not visited.count(nei))
        {
            dfs(nei,visited);
        }
    }
}
int cc(int v)
{
    int result=0;
    unordered_set<int>visited;
    for(int i=0;i<v;i++)
    {
        if(visited.count(i)==0)
        {
            result++;
            dfs(i,visited);
        }
    }
    return result;
}
int main() {
    int v,e;
    cout<<"enter the number of vertices";
   cin>>v;
   graph.resize(v,list<int>());
   cout<<"enter the number of edges";
   cin>>e;
   while(e--)
   {
       cout<<"enter s and d";
       int s,d;
       cout<<"enter";
       cin>>s>>d;
       add_edge(s,d,true);
   }
   cout<<cc(v);
}
