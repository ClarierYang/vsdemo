#include <bits/stdc++.h>
using namespace std;
typedef struct{
    int key;//记录指针
    int next;//指针项
}SLnode;
void Linsertsort(SLnode k[],int n)
{
    //0号单元为表头结点，并设表头结点的关键字取最大整数MAXINT
    k[0].key = INT_MAX;
    k[0].next = 1;
    k[1].next = 0;  //静态链表中数组下表为1的分量和表头结点构成一个循环链表
    for(int i=2;i<=n;i++)
    {
       int t=k[0].next;
       int j;
        for(j=0;k[t].key<=k[i].key;j=t,t=k[t].next){}
        k[j].next=i;k[i].next=t;//结点i插入结点j和结点t之间
    }
    }
void arrange(SLnode k[],int n)
{
    int p,q;
    p=k[0].next;//p指示第一个记录的位置
    for(int i=1;i<n;i++)
    {
        //k[1···i-1]中记录已经按关键字有序排列
        //第i个记录在k中的当前位置应该不小于i
        while(p<i) p=k[p].next;//找到第i个记录，并用p指示其中k中的当前位置
        q=k[p].next;//q指示尚未调整的表尾
        if(p!=i)
        {
            int temp=k[p].key;
            k[p].key=k[i].key;
            k[i].key=temp;
            k[i].next=p;//指向被移走的记录，使得以后可以由while循环找回
        }
        p=q;//p指向尚未调整的表尾，为找到第i+1个记录作准备
    }
}
int main()
{
    int n;
    SLnode k[100];
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>k[i].key;
    Linsertsort(k,n);
   arrange(k,n);
    for(int i=1;i<=n;i++)
    {cout<<k[i].key<<" ";}

}