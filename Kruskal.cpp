#include<iostream>
#include<algorithm>
using namespace std;
int const maxn=1000;
struct edge
{
    int from,to;
    int w;
}e[maxn];
int fa[maxn],n,m;
bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x)
{
    if(fa[x]==x) return x;
    else return find(fa[x]); 
}
int kruskal()
{
    int ans=0;
    for(int i=0;i<n;i++) fa[i]=i;
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++)
    {
        edge e1=e[i];
        int x=find(e1.from);
        int y=find(e1.to);
        if(x!=y){ans+=e1.w;fa[x]=y;}
    }
    return ans;
}
int main()
{
    //输入需要的数据即可
}

