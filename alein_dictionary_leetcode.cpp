// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;
vector<list<int>>graph;
queue<int>q;
unordered_set<int>visi;
unordered_map<char,int>m;
void add_edge(int src,int dst)
{
    graph[src].push_back(dst);
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<char(i+97)<<"->";
        for(auto ele:graph[i])
        {
            cout<<char(ele+97);
        }
        cout<<"\n";
    }
}
void topobfs()
{
    int v=26;
    vector<int>id(26,0);
    for(int i=0;i<26;i++)
    {
        for(auto nei:graph[i])
        {
            id[nei]++;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(id[i]==0)
        {
            q.push(i);
            visi.insert(i);
        }
    }
    while(not q.empty())
    {
        int node=q.front();
        char s=char(node+97);
        if(m.find(s)!=m.end()) cout<<char(node+97)<<" ";
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
void f(vector<string>&words)
{
    graph.resize(26,list<int>());
    int n=words.size();
    for(int i=0;i<n-1;i++)
    {
        string w1=words[i];
        string w2=words[i+1];
        for(int j=0;j<min(w1.size(),w2.size());j++)
        {
            if(w1[j]!=w2[j])
            {
                add_edge(w1[j]-'a',w2[j]-'a');
                break;
            }
        }
    }
    display();
    topobfs();
}
int main() {
    vector<string>words={"wrt","wrf","er","ett","rftt"};
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words[i].size();j++)
        {
            m[words[i][j]]++;
        }
    }

    f(words);
    
}
