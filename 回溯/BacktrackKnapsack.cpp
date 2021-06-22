#include<bits/stdc++.h>
using namespace std;
int const maxn=1000;
int n,W;
int cw=0,cv=0,bestv=0,bestx[maxn],x[maxn];
struct item{
    int v,w;
}a[maxn];
bool compare(item a,item b)
{
    return (double)a.v/a.w>(double)b.v/b.w;
}
double r(int i)
{
    int rw=W-cw;
    double ri=cv;
    while(i<n&&a[i+1].w<=rw)
    {
        rw-=a[i+1].w;
        ri+=a[i+1].v;
        i++;
    }
    if(i<n) ri+=(a[i+1].v/a[i+1].w)*rw;
    return ri;
}
void BacktrackKnapsack(int i)
{
    if(i>n)
    {
        if(cv>bestv) 
            {bestv=cv;
            for(int j=1;i<=n;j++)
                bestx[i]=x[i];
            }
    }
    else
    {
        if(cw+a[i].w<=W)
        {
            x[i]=1;
            cw+=a[i].w;cv+=a[i].v;
            BacktrackKnapsack(i+1);
            cw-=a[i].w;cv-=a[i].v;
        }
        else
        {
            if(r(i)>bestv)
            {
                x[i]=0;
                BacktrackKnapsack(i+1);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].v;
    for (int i = 1; i <= n; i++) cin >> a[i].w;
    cin>>W;
    sort(a,a+n,compare);
    BacktrackKnapsack(1);
    cout<<bestv<<endl;
}