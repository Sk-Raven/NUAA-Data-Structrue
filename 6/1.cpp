#include <iostream>
#include <malloc.h>
#include <queue>
#include <string.h>
using namespace std;
int **g;
int *p;
int n;
bool vis[100];
void create()
{   g=(int**)malloc(n* sizeof(int*));
    p=(int*)malloc(n* sizeof(int));
    for(int k=0;k<n;k++)
    {
        g[k] = (int *) malloc(n* sizeof(int));
        memset(g[k],0,n);
    }
}

void destroy()
{
    for(int k=0;k<n;k++)
       free(g[k]);
    free(g);
    free(p);

}

int Locate(int *u)
{ for(int k=0;k<n;k++)
    {
        if(g[k]==u)
            return k;
    }

    int flag= true;
for(int k=0;k<n;k++)
{   flag= true;
    for(int l=0;l<n;l++)
    {
        if(u[l]!=g[k][l])
        {
            flag= false;
            break;
        }
    }
    if(flag)
        return k;
}
    return -1;
}

int get(int *u)
{
    return p[Locate(u)];
}

void put(int *v,int value)
{
    p[Locate(v)]=value;
}

int* first(int *v)
{
 for(int k=0;k<n;k++)
 {
     if(v[k]!=0)
         return g[k];
 }
    return NULL;
}

int* next(int *v,int *u)
{
    for(int k=Locate(u)+1;k<n;k++)
    {
        if(v[k]!=0)
            return g[k];
    }
    return NULL;
}
void insertVex(int *v,int num)
{   n++;
    realloc(p,n* sizeof(int));
    p[n-1]=num;
    realloc(g,n* sizeof(int*));
    for(int k=0;k<n;k++)
    {
        realloc(g[k],n* sizeof(int));
        memset(g[k],0,n);
    }

    for(int k=0;k<n;k++)
    {
        if(v[k]==1)
            g[k][n-1]=1;
    }
}
void deleteVex(int *v)
{   int loc=Locate(v);
    int *pt=(int*)malloc((n-1)* sizeof(int));
    int **gt=(int **)malloc((n-1)* sizeof(int*));
    for(int k=0;k<n-1;k++)
    {
        gt[k] = (int *) malloc((n - 1)* sizeof(int));
        memset(gt[k],0,n-1);
    }

    for(int k=0;k<n;k++)
    {
        if(k==loc)
            continue;

        pt[k]=p[k];
    }

    for(int k=0;k<n;k++)
    {
        if(k==loc)
            continue;
        for(int l=0;l<n;l++)
        {
            if(l==loc)
                continue;
            gt[k][l]=g[k][l];
        }
    }

    destroy();
    g=gt;
    p=pt;
    pt=NULL;
    gt=NULL;

}

void insertarc(int *u,int *v)
{
    int k=Locate(u);
    int l=Locate(v);
    g[k][l]=1;
    g[l][k]=1;
}

void deletearc(int *u,int *v)
{
    int k=Locate(u);
    int l=Locate(v);
    g[k][l]=0;
    g[l][k]=0;
}

void clear()
{
    for(int k=0;k<100;k++)
        vis[k]= false;
}
void DFS(int *v)
{   int loc=Locate(v);
    vis[loc]= true;
    bool flag= true;
    for(int k=0;k<n;k++)
    {
        if(vis[k]== false)
            flag=false;
    }
    if(flag)
        return;

    for(int k=0;k<n;k++)
    {
      if(g[loc][k]==1&&vis[k]== false)
      {
          printf("%d ",k);
          DFS(g[k]);
      }
    }


}

void BFS(int *v)
{
    queue<int*> q;
    q.push(v);
    int temp=Locate(v);
    printf("%d ",temp);
    vis[Locate(v)]= true;
    while(!q.empty())
    {
        for(int k=0;k<n;k++)
        {
            if(g[temp][k]==1&&vis[k]== false)
            {   printf("%d ",k);
                vis[k]= true;
                q.push(g[k]);
            }
        }
        q.pop();
        if(!q.empty())
        temp=Locate(q.front());

    }
}
int main()
{
 scanf("%d",&n);
    create();
    for(int k=0;k<n;k++)
        p[k]=k;
    g[0][1]=1;
    g[1][0]=1;
    g[1][4]=1;
    g[4][1]=1;
    g[1][2]=1;
    g[2][1]=1;
    g[1][3]=1;
    g[3][1]=1;
    g[0][2]=1;
    g[2][0]=1;
    g[0][3]=1;
    g[3][0]=1;
    g[3][5]=1;
    g[5][3]=1;
    g[5][6]=1;
    g[6][5]=1;
    g[2][6]=1;
    g[6][2]=1;
    clear();
    printf("DFS:%d ",0);
    DFS(g[0]);
    clear();
    cout<<endl;
    printf("BFS:");
    BFS(g[0]);
    clear();
    deleteVex(g[6]);
    cout<<endl<<"delete 6"<<endl;
    printf("DFS:%d ",0);
    DFS(g[0]);
    destroy();
    return 0;
}