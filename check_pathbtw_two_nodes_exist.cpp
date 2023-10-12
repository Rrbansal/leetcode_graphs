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
bool dfs(int curr,int end)
{
    if(curr==end) return true;
    visited.insert(curr);
    for(auto nei:graph[curr])
    {
        if(not visited.count(nei))
        {
            bool result=dfs(nei,end);
             if(result) return true;
        }
    }
    return false;
    
}
bool any_path(int src,int dst)
{
    return dfs(src,dst);
    
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
   int x,y;
   cout<<"enter the nodes";
   cin>>x>>y;
   cout<< any_path(x,y);
   

    return 0;
}
