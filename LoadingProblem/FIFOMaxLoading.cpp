#include <iostream>
#include<queue>
using namespace std;
int const maxn = 1000;
int n, w[maxn], W, bestw=0;
queue<int>Q;
int FIFOMxaLoadind()
{
    int i=1;
    Q.push(-1);
    int cw=0,r=0;
    for(int j=2;j<=n;j++) r+=w[i];
    while(!Q.empty())
    {
        if(cw+w[i]<=W)
        {
            if(cw+w[i]>bestw) bestw=cw+w[i];
            if(i<n) Q.push(cw+w[i]);
        }
        if(cw+r>bestw&&i<n) Q.push(cw);
        cw=Q.front();
        Q.pop();
        if(cw==-1)
            if(Q.empty()) return bestw;
            else
            {
                Q.push(-1);
                cw=Q.front();
                Q.pop();
                i++;
                r-=w[i];
            }
    }
}
int main()
{
    cin>>n>>W;
    for(int i=1;i<=n;i++) cin>>w[i];
    cout<<FIFOMxaLoadind();
}