#include <bits/stdc++.h>
using namespace std;
int const maxn = 1000;
int n,w[maxn][maxn],x[maxn],cw=0,bestw=0,bestx[maxn];
int const INF;
void BacktrackTSP(int i)
{
    if(i==n)
        {
            if(w[x[n-1]][x[n]]!=INF&&w[x[n]][1]!=INF)
                if(cw+w[x[n-1]][x[n]]+w[x[n]][1]<bestw)
                {
                    bestw = cw + w[x[n - 1]][x[n]] + w[x[n]][1];
                    for(int j=1;j<=n;j++) bestx[j]=x[j];
                }
        }
    else
        {
            for(int j=1;j<=n;j++)
            if(w[x[i-1]][x[j]]!=INF&&cw+w[x[i-1]][x[j]]<bestw)
                {
                swap(x[i], x[j]);
                cw += w[x[i - 1]][x[i]];
                BacktrackTSP(i + 1);
                cw -= w[x[i - 1]][x[i]];
                swap(x[i], x[j]);
                }
        }
        
}