#include<iostream>
using namespace std;
char b[9][9],board[9][9];
bool place(int x,int y,char c)
{
    for(int k=0;k<9;k++) //判断同一行同一列是否已经出现过相同数字
    {
        if(b[x][k]==c) return false;
        if(b[k][y]==c) return false;
    }
    for(int k=x/3*3;k<x/3*3+3;k++)//判断属于的那个九宫格里是否已经出现相同数字
        for(int t=y/3*3;t<y/3*3+3;t++)
            if(b[k][t]==c) return false;
    return true;
}
bool Backtracksudo(int cur)
{
    if(cur==81)//cur=81，说明已经全部填好了
    {
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++) board[i][j]=b[i][j];
        return 1;
    }
    int x=cur/9;
    int y=cur%9;
    if(b[x][y]!='.')//已经放了数字了
        Backtracksudo(cur+1);
    else
    {
        for(char c='1';c<='9';c++)
            if(place(x,y,c))
            {
                b[x][y]=c;
                cout<<cur<<" "<<c<<endl;
                if(Backtracksudo(cur+1)) return 1;
                b[x][y]='.';
            }
    }
    return 0;
}
int main()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++) cin>>b[i][j];
    Backtracksudo(0);
    for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) cout<<board[i][j]<<" ";
            cout<<endl;
        }
}