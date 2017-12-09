#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int num[100];
int n;
class treenode {
public:
    int data;
    treenode *lch;
    treenode *rch;
    treenode(int s)
    {   data=s;
        lch=NULL;
        rch=NULL;
    }

};

void destroy(treenode *node)
{
    if(node->lch!=NULL)
        destroy(node->lch);
    if(node->rch!=NULL)
        destroy(node->rch);

    delete []node;
}

int main()
{
    cin>>n;
    for(int k=0;k<n;k++)
        scanf("%d",&num[k]);

    sort(num,num+n);
    treenode *treenode1=new treenode(num[0]);
    treenode *treenode2=new treenode(num[1]);
    treenode *node=new treenode(num[0]+num[1]);
    node->lch=treenode1;
    node->rch=treenode2;
    for(int k=2;k<n;k++)
    {   treenode *temp=node;
        treenode *t=new treenode(num[k]);
        node=new treenode(num[k]+node->data);
       if(node->data>num[k])
       {
          node->rch=temp;
           node->lch=t;
       }
        if(node->data>num[k])
        {
            node->lch=temp;
            node->rch=t;
        }

    }
    queue<treenode*> q;
    q.push(node);
    while(!q.empty())
    {
        treenode *temp=q.front();
        if(temp->lch!=NULL)
            q.push(temp->lch);
        if(temp->rch!=NULL)
            q.push(temp->rch);
        if(temp->lch==NULL&&temp->rch==NULL)
            printf("%d",temp->data);

        q.pop();
    }




}