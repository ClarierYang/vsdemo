#include<bits/stdc++.h>
using namespace std;
int const maxn=1000;
int n,x[maxn],Solnum=0;
bool Place(int k)
{
    for(int j=1;j<k;j++)
    if(abs(x[j]-x[k])==abs(k-j)||x[k]==x[j])
    return false;
    return true;
}
void BacktrackNqueen()
{
    x[1]=0;
    int k=1;
    while(k>0)
    {
        while(x[k]<=n-1)
        {
            x[k]+=1;
            if(Place(k))
                if(k==n)
                    Solnum+=1;
                else
                    {
                        k+=1;
                        x[k]=0;
                    }
        }
        k-=1;
    }
}
int main()
{
    cin>>n;
    BacktrackNqueen();
    cout<<Solnum<<endl;
}