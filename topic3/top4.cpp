#include<iostream>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
#include<time.h>
using namespace std;
#define colMAX 200
#define rowMAX 6000
#define CandyNumber 200
#define CandyWeight 100
#define INF 2147483647

int testnumbers,n;//Input
unsigned long long A[rowMAX][colMAX];
int Candy[CandyNumber];
int CandySum;
time_t a,b,c,d;
void input()
{
    CandySum=0;
    for(int i=0;i<n;i++)
    {
        cin>>Candy[i];
        CandySum=CandySum+Candy[i];
    }
}

int search(int a,int b,int c)
{
    return(max(max(a,b),c)-min(min(a,b),c));
}

int calculate()
{
    int answer=INF;
    memset(A,0,sizeof(A));
    A[0][0]=1;
    int carre,mod;
    long long top,down;
    long long tmp;
    long long atmp;
    int id;
    for(int i=0;i<n;i++)//candy number
    {
        carre = Candy[i]/32;
        mod = Candy[i]%64;
        for(int j=int(CandySum);j>=0;j--)
        {
            for(int k=int(CandySum/32);k>=0;k--)
            {
                if(A[j][k]!=0)
                {
                    tmp=(A[j][k]<<mod);
                    top=(tmp>>32)&0xffffffff;
                    down=(tmp)&0xffffffff;
                    A[j+Candy[i]][k]|=(A[j][k]);
                    A[j][k+carre]|=(down);
                    A[j][k+carre+1]|=(top);
                }
            }
        }
    }
    for(int j=0;j<=CandySum;j++)
    {
        for(int k=0;k<=CandySum/32;k++)
        {
            if(A[j][k])
            {
                atmp=A[j][k];
                id=0;
                for(int i=0;i<32;i++)
                {
                    if(atmp%2==1)
                    {
                        answer = min(answer,search(j,32*k+id,CandySum-j-32*k-id));
                    }
                    id++;
                    atmp=atmp/2;
                }

            }
        }
    }
    return answer;
}

int main()
{
    cin>>testnumbers;
    c = clock();
    for(int testnumber=1;testnumber<=testnumbers;testnumber++)
    {
        cin>>n;
        input();
        cout<<"Case "<<testnumber<<": "<<calculate()<<endl;
    }
    d=clock();
    return 0;
}