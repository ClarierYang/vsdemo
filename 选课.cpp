#include<iostream>
#include<algorithm>
using namespace std;
int const maxn=31;
int in[maxn];//记录前置课程数
struct vertice
{
    int w,index;//每门课的兴趣值
    bool visited=false;
    int out=0;//out表示作为别的课的前置课的数
    int outv[maxn];
}v[maxn];
bool cmp(vertice a,vertice b)
{
    return a.w>b.w;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i].w;
    for(int i=1;i<=n;i++) 
    {
        cin>>in[i];
        v[i].index=i;
            for(int j=0;j<in[i];j++)
            {
                int tmp;
                cin>>tmp;
                v[tmp].outv[v[tmp].out++]=i;
            }
    }
    sort(v+1,v+n+1,cmp);
    for(int i=1;i<=n;i++)cout<<in[v[i].index]<<" ";cout<<endl;
    int x[maxn];
    for(int t=0;t<n;t++)
        for(int i=1;i<=n;i++)
            {
                if(!in[v[i].index]&&!v[i].visited)
                {
                    v[i].visited=true;
                    x[t]=v[i].index;
                    for(int j=0;j<v[i].out;j++)
                    {
                        int tmp=v[i].outv[j];
                        in[tmp]--;
                    }
                    break;
                }
            }
    for(int i=1;i<=n;i++) cout<<v[i].w<<" ";cout<<endl;
  
    for(int i=0;i<n;i++) cout<<x[i]<<" ";
}
