#include <iostream>
using namespace std;
int graph[100][100];
int visit[100];
int n;
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
{int m;
 scanf("%d %d",&n,&m);
    for(int k=0;k<m;k++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
    }
    bool flag= false;
    while(!over())
    {
      for(int k=0;k<n;k++)
      {   if(visit[k]== true)
              continue;
          for(int l=0;l<n;l++)
          {
              if(graph[l][k]==1&&!visit[l])
              {
                  flag= true;
                  continue;
              }
          }
          if(flag== true)
              flag= false;
          else
          {
              printf("%d",k);
              visit[k]= true;
          }

      }
    }

}