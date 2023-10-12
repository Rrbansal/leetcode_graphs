// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
#include<climits>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
queue<int>q;
int ve;
void add_edge(int src,int dst,bool bir)
{
    graph[src].push_back(dst);
    if(bir==true)
    {
        graph[dst].push_back(src);
    }
    
}
void bfs(int src,vector<int>&dis)
{
    dis.resize(ve,INT_MAX);
    dis[src]=0;
    visited.insert(src);
    q.push(src);
    while(not q.empty())
    {
        int curr=q.front();
        cout<<curr;
        q.pop();
        for(auto nei:graph[curr])
        {
            if(not visited.count(nei))
            {
                q.push(nei);
                visited.insert(nei);
                dis[nei]=dis[curr]+1;
            }
        }
    }
    
}

int main() {
    int v,e;
    cout<<"enter the number of vertices";
    cin>>v;
    ve=v;
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
   cin>>x;
   vector<int>dis;
   bfs(x,dis);
   for(int i=0;i<dis.size();i++)
   {
       cout<<dis[i];
   }
  

    return 0;
}
