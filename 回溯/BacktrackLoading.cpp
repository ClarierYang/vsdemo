#include<bits/stdc++.h>
using namespace std;
int const maxn=1000;
int n,w[maxn],W,x[maxn],bestx[maxn];
int bestw=0,r=0,cw=0;
void ImprovedBacktrackLoading(int i)
{
    if(i>n)
        {if(cw>bestw)
            {
                bestw=cw;
                for(int j=1;i<=n;j++) bestx[j]=x[j];
            }}
    else
        {
            r-=w[i];
            if(cw+w[i]<=W)//C[i]=cw+w[i];C[i]表示取了第i件物品后的重量
                {
                    x[i]=1;
                    cw+=w[i];
                    ImprovedBacktrackLoading(i+1);
                    cw-=w[i];
                }
            if(r+cw>bestw)
                    { x[i]=0;//判断不取第i件的分支是不是要走
                    ImprovedBacktrackLoading(i+1);}
            r+=w[i];
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>w[i];
        r+=w[i];
    }
    cin>>W;
    ImprovedBacktrackLoading(1);
    cout<<bestw<<endl;
}