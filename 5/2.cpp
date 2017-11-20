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



void PreOrderTraverse(BiTree T)
{
    stack<BiTNode *> node;
    BiTNode *n=T;
    node.push(n);
    while(n!=NULL||!node.empty())
    {
       while (n!=NULL){
            printf("%d ",n->data);
            
            node.push(n);
            n=n->left;
    }
        if(!node.empty()){
            n=node.top();
            node.pop();
            n=n->right;
            if(node.empty())
            n=NULL;

        }
    }
    }
    





void MidOrderTraverse(BiTree T) {
    stack<BiTNode *> node;
    BiTNode *n = T;
    node.push(n);
    while (n != NULL || !node.empty()) {
        while (n != NULL) {
            node.push(n);
            n = n->left;
        }
        if (!node.empty()) {
            n = node.top();
            node.pop();
             if(node.empty())
             return;
            printf("%d ",n->data);
            n = n->right;
             

        }
        
    }
    
}



void AftOrderTraverse(BiTree T){
        stack<BiTNode *> node;
        BiTNode *n = T;
        BiTNode *last=T;
        node.push(n);
        while(!(n==NULL&&node.empty())){
            while (n!=NULL){
                node.push(n);
                n=n->left;
            }
            
            n=node.top();
            if(n->right==NULL||n->right==last){
                printf("%d ",n->data);
                if(n==T)
                 return;
                node.pop();
                last=n;
                n=NULL;
            }
            else{n=n->right;


            }

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



int main()
{
 BiTree T;
    CreateBiTee(T);
    
    
   PreOrderTraverse(T);
   cout<<endl;
   MidOrderTraverse(T);
   cout<<endl;
   AftOrderTraverse(T);
   cout<<endl;
   CZOrderTraverse(T);
    Destroy(T);
    

}
