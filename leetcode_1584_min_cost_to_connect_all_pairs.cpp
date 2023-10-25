
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
class Solution {
public:
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
int kruskal(vector<edge>&input,int n,int e)
{
     sort(input.begin(),input.end(),cmp);
     int ec=0,i=0;
     int ans=0;
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int e=(n*(n-1))/2;
        vector<edge>v(e);
        par.resize(n+1);
        r.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                v[c].src=i;
                v[c].dst=j;
                v[c].wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                c++;
            }
        }
        return kruskal(v,n,e);
        
    }
};
