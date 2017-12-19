#include <iostream>
#include <queue>

using namespace std;
bool visited[100];
int n;
int dis[100];
int graph[100][100];
void dij()
{
    for(int k=0;k<n;k++)
        dis[k]=9999999;
    dis[0]=0;
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<n;j++)
        {   if(graph[k][j]!=0)
            if((dis[k]+graph[k][j])<dis[j])
                dis[j]=dis[k]+graph[k][j];
        }
    }

}

int main()
{   int m;
    cin>>n>>m;
    int a,b,c;
    for(int k=0;k<m;k++)
    {
        scanf("%d %d %d",&a,&b,&c);
        graph[a][b]=c;
        graph[b][a]=c;
    }
    graph[0][1]=7;
    graph[1][0]=7;
    graph[0][2]=9;
    graph[2][0]=9;
    graph[0][5]=14;
    graph[5][0]=14;
    graph[1][2]=10;
    graph[2][1]=10;
    graph[1][3]=15;
    graph[3][1]=15;
    graph[2][3]=11;
    graph[3][2]=11;
    graph[2][5]=2;
    graph[5][2]=2;
    graph[3][4]=6;
    graph[4][3]=6;
    graph[4][5]=9;
    graph[5][4]=9;
    dij();
    for(int k=1;k<n;k++)
        printf("%d ",dis[k]);


}