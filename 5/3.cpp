#include <iostream>
#include <stack>
#include <queue>
#include <malloc.h>
using namespace std;
typedef struct BiTNode
{
    int data;
    BiTNode *left;
    BiTNode *right;
}BiTNode,*BiTree;
bool BiTNodeequals(BiTNode a,BiTNode b)
{
    if(a.data==b.data&&a.left==b.left&&a.right==b.right)
        return true;
    else
        return false;
}
void Destroy(BiTree T)
{
    if(T)
    {
        if(T->left)
            Destroy(T->left);
        if(T->right)
            Destroy(T->right);

        free(T);

    }
}
void CreateBiTee(BiTree &T)
{   int ch;
    scanf("%d",&ch);
    if(ch==0)
        T=NULL;
    else{
        T=(BiTNode *)malloc(sizeof(BiTNode));
        T->data=ch;
        CreateBiTee(T->left);
        CreateBiTee(T->right);


    }

}
BiTNode* Parent(BiTree T,BiTNode *e)
{
    queue<BiTNode *> node;
    node.push(T);
    while(!node.empty())
    {
        T=node.front();
        if(BiTNodeequals(*(T->left),*e)||BiTNodeequals(*(T->right),*e))
            return T;
        else {
            if(T->left)
            node.push(T->left);
            if(T->right)
            node.push(T->right);
        }



        node.pop();
    }
    return NULL;
}
void Delete(BiTree T,int data){

    queue<BiTNode *>node;
    BiTNode *n=T;
    node.push(n);
    while(n!=NULL||!node.empty())
    {   n=node.front();
        node.pop();
        if(n->data==data)
        {   if(Parent(T,n)->left==n)
               Parent(T,n)->left=NULL;
            else
               Parent(T,n)->right=NULL;
            
            Destroy(n);
            n=NULL;
            continue;
        }
        if(n->left)
        node.push(n->left);
        if(n->right)
            node.push(n->right);
        n=NULL;
    }
}

void CZOrderTraverse(BiTree T){
    queue<BiTNode *>node;
    BiTNode *n=T;
    node.push(n);
    while(n!=NULL||!node.empty())
    {   n=node.front();
        printf("%d ",n->data);
        node.pop();
        if(n->left)
            node.push(n->left);
        if(n->right)
            node.push(n->right);
        n=NULL;
    }

}
void Destroy(BiTree T)
{
 if(T)
 {
     if(T->left)
         Destroy(T->left);
     if(T->right)
         Destroy(T->right);

     free(T);

 }
}


int main()
{
    BiTree T;
    CreateBiTee(T);
    Delete(T,2);
    cout<<"Detele data=2,ÏÈÐò±éÀú£º"<<endl;
    CZOrderTraverse(T);
    Destroy(T);
    
}

