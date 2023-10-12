// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<unordered_map<int,int>>graph;
void add_edge(int src,int dst,int wt,bool bir=true)
{
    graph[src][dst]=wt;
    if(bir)
    {
        graph[dst][src]=wt;
    }
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(auto ele:graph[i])
        {
            cout<<"("<<ele.first<<" "<<ele.second<<")";
        }
        cout<<"\n";
    }
}

int main() {
    int v,e,wt;
    cout<<"enter the number of vertices";
   cin>>v;
   graph.resize(v,unordered_map<int,int>());
   cout<<"enter the number of edges";
   cin>>e;
   while(e--)
   {
       cout<<"enter s and d and wt";
       int s,d;
       cout<<"enter";
       cin>>s>>d>>wt;
       add_edge(s,d,wt,true);
   }
   display();
}
