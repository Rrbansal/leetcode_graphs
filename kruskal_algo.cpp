// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>par;
vector<int>r;
int find(int a)
{
    if(par[a]==a) return a;
    return find(par[a]);
}
void un(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(r[a]>r[b])
    {
        r[a]++;
        par[b]=a;
    }
    else
    {
        r[b]++;
        par[a]=b;
    }
}
struct edge
{
    int src;
    int dst;
    int wt;
};
bool cmp(edge e1,edge e2)
{
    return e1.wt<e2.wt;
}

long long int kruskal(vector<edge>&input,int n,int e)
{
     sort(input.begin(),input.end(),cmp);
     int ec=0,i=0;
     long long int ans=0;
     while(ec<n-1 and i<input.size())
     {
         edge curr=input[i];
         int srcpar=find(curr.src);
         int dstpar=find(curr.dst);
         if(srcpar!=dstpar)
         {
             un(srcpar,dstpar);
             ans+=curr.wt;
             ec++;
         }
         i++;
         
     }
     return ans;
}
int main() {
    int n,e;
    cout<<"enter n and e";
    cin>>n>>e;
    vector<edge>v(e);
     par.resize(n+1);
     r.resize(n+1,1);
     for(int i=0;i<=n;i++) par[i]=i;
    for(int i=0;i<e;i++)
    {
        cin>>v[i].src>>v[i].dst>>v[i].wt;
    }
    cout<<kruskal(v,n,e);
  

    return 0;
}
