#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <malloc.h>
#include <math.h>
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

int TreeDepth(BiTree T)
{
    int right=0;
    int left=0;

    if(T==NULL)
        return -1;

    if(T->left!=NULL)
        left=TreeDepth(T->left);
    else
        left=-1;

    if(T->right!=NULL)
        right=TreeDepth(T->right);
    else
        right=-1;

    return (right>left) ? right+1 : left+1;
}

BiTNode* Parent(BiTree T,BiTNode *e)
{
    queue<BiTNode *> node;
    BiTNode *a;
    node.push(T);
    while(!node.empty())
    {
        a=node.front();
        if(a->left==e||a->right==e)
            return a;
        else {
            if(a->left)
                node.push(T->left);
            if(a->right)
                node.push(T->right);
        }



        node.pop();
    }
    return NULL;
}

int Depth(BiTree T,BiTNode *n)
 {
 if(n==T)
 {
    return 0;
 }
   int deep=1;BiTNode *a=n;
   while(Parent(T,a)!=T){
       a=Parent(T,a);
       deep++;
   }
    return deep;

}

bool CBTree(BiTree T)
{
    int deep=TreeDepth(T);
    vector<BiTNode *>node;
    BiTNode *n=T;
    node.push_back(n);
    int k=0;
    while(k<=node.size()-1){
        if(node[k]->left)
            node.push_back(node[k]->left);
        if(node[k]->right)
            node.push_back(node[k]->right);
        k++;
    }
    if(node.size()==((int)pow(2,deep+1)-1))
        return true;
    if(node.size()<=((int)pow(2,deep)-1))
        return false;
    k--;
    while(Depth(T,node[k])!=(deep-1))
    {
        node.pop_back();
        k--;
    }
    if(node.size()!=((int)pow(2,deep)-1))
        return false;

    while(Depth(T,node[k])!=(deep-2))
    {
        if(node[k]->right)
            if(!node[k]->left)
                return false;
        k--;
    }
    return true;


}


int main()
{
    BiTree T;
    CreateBiTee(T);
    if(CBTree(T))
    cout<<"yes";
    else
    cout<<"no";
}

