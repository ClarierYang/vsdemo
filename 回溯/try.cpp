#include<iostream>
using namespace std;
int main()
{
    char c[10];
    int count=0;
    for(char i='1';i<='9';i++)
    c[count++]=i;
    for (int i = 0; i < 10; i++) cout << c[i]<<" ";
}