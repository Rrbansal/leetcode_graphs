// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
vector<vector<int>>result;
void add_edge(int src,int dst,bool bir)
{
    graph[src].push_back(dst);
    if(bir==true)
    {
        graph[dst].push_back(src);
    }
    
}
void dfs(int curr,int end,vector<int>&path)
{
    if(curr==end)
    {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return ;
        
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto nei:graph[curr])
    {
        if(not visited.count(nei))
        {
          dfs(nei,end,path);
             
        }
    }
    path.pop_back();
    visited.erase(curr);
    return ;
    
}
void all_path(int src,int dst)
{
    vector<int>v;
    dfs(src,dst,v);
    
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
   all_path(x,y);
   for(auto path:result)
   {
       for(auto ele:path)
       {
           cout<<ele;
       }
       cout<<"\n";
   }
   

    return 0;
}
