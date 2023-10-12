// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<list>
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
   display();
}
