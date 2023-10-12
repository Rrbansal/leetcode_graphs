// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
void add_edge(int src,int dst,bool bir)
{
    graph[src].push_back(dst);
    if(bir==true)
    {
        graph[dst].push_back(src);
    }
    
}
void dfs(int curr)
{
    cout<<curr;
    visited.insert(curr);
    for(auto nei:graph[curr])
    {
        if(not visited.count(nei)) dfs(nei);
    }
    return;
    
}
int main() {
    int v,e;
    cout<<"enter the number of vertices";
    cin>>v;
    cout<<"enter the number of edges";
    cin>>e;
    graph.resize(v,list<int>());
   while(e--)
   {
       int src,dst;
       cin>>src>>dst;
       add_edge(src,dst,true);
   }
   int x;
   cout<<"enter the nodes";
   cin>>x;
dfs(x);
   

    return 0;
}
