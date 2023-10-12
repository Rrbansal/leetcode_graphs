// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<unordered_set<int>>graph;
void add_edge(int src,int dst,bool bir=true)
{
    graph[src].insert(dst);
    if(bir)
    {
        graph[dst].insert(src);
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

int main() {
    int v,e,wt;
    cout<<"enter the number of vertices";
   cin>>v;
   graph.resize(v,unordered_set<int>());
   cout<<"enter the number of edges";
   cin>>e;
   while(e--)
   {
       cout<<"enter s and d and wt";
       int s,d;
       cout<<"enter";
       cin>>s>>d;
       add_edge(s,d,true);
   }
   display();
}
