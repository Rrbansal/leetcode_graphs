// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
queue<int>q;
unordered_set<int>visi;
int v,e;
void add_edge(int a,int b,int bir=true)
{
    graph[a].push_back(b);
    if(bir)
    {
        graph[b].push_back(a);
    }
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(auto ele:graph[i])
        {
            cout<<ele;
        }
        cout<<"\n";
    }
}
void topobfs()
{
    cout<<"gg";
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
    cout<<"starting";
    while(not q.empty())
    {
        int node=q.front();
        cout<<node;
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
int main() {
    cout<<"enter vertices and edges";
    cin>>v>>e;
    graph.resize(v,list<int>());
    while(e--)
    {
        cout<<"enter";
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    display();
    topobfs();
    
}
