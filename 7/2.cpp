#include <iostream>
using namespace std;
int graph[100][100];
bool visit[100];
int n;
int dis;
bool over()
{
    for(int k=0;k<n;k++)
    {
        if(visit[k]== false)
            return false;
    }
    return true;
}
int main()
{   int m;
    scanf("%d %d",&n,&m);
    for(int k=0;k<m;k++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a-1][b-1]=c;
        graph[b-1][a-1]=c;
    }
    visit[0]= true;
    while(!over())
    {   int min=0;
        int temp=9999999;
        for(int k=0;k<n;k++)
        {
            if(visit[k]== true)
            {
                for(int l=0;l<n;l++)
                {
                    if(visit[l]== true)
                        continue;

                    if(graph[k][l]<temp&&graph[k][l]!=0)
                    {
                        temp=graph[k][l];
                        min=l;
                    }
                }
            }
        }
        visit[min]= true;
        dis+=temp;
    }
    printf("%d",dis);
}