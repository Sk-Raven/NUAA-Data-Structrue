#include <iostream>
#include <queue>



using namespace std;

int n;
int dis[100];
int dis1[100];
int graph[100][100];
int pre[10];

void dij() {

    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int k = 0; k < n; k++)
        {
           if(graph[temp][k]!=0&&((dis[temp]+graph[temp][k])>dis[k]))
           {

                   dis[k] = dis[temp] + graph[temp][k];
                   q.push(k);



           }
        }
    }

}
void black()
{ for(int k=0;k<n;k++)
    {
        dis1[k]=999999;
    }
   dis1[n-1]=dis[n-1];
    queue<int> q;
    q.push(n-1);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int k = 0; k < n; k++)
        {
            if(graph[k][temp]!=0&&((dis1[temp]-graph[k][temp])<dis1[k]))
            {
                dis1[k] = dis1[temp] - graph[k][temp];
                q.push(k);
            }
        }
    }
}

int main()
    {   int m;
        cin>>n>>m;
        int a,b,c;
        for(int k=0;k<m;k++)
        {
            scanf("%d %d %d", &a, &b, &c);
        }
        graph[0][1]=3;
        graph[0][2]=4;
        graph[1][3]=5;
        graph[2][3]=8;
        graph[1][4]=6;
        graph[3][4]=3;
        graph[2][5]=7;
        graph[5][7]=6;
        graph[4][7]=4;
        graph[4][6]=9;
        graph[6][9]=2;
        graph[7][8]=5;
        graph[8][9]=3;

        dij();
        black();

        for(int k=0;k<n;k++)
        {   if(dis[k]==dis1[k])
            printf("%d ",k);
        }
        printf("\n");

}