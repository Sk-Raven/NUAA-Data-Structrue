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
void Init(BiTNode &T)
{
    T.data=0;
    T.left=NULL;
    T.right=NULL;


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

void clear(BiTree &T)
{
  T->data=0;
    if(T->left)
        clear(T->left);
    if(T->right)
        clear(T->right);
}

bool Empty(BiTNode *T)
{queue<BiTNode *> node;
    node.push(T);
    while(!node.empty())
    {
      T=node.front();
        if(T->data!=0)
            return false;
        if(T->left)
            node.push(T->left);
        if(T->right)
            node.push(T->right);

        node.pop();
    }
    return true;


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

BiTree Root(BiTree T)
        {
            return T;
        }
int Value(BiTree T,BiTNode *e)
{
    if(!T)
        return 0;

    return e->data;
}

void Assign(BiTree T,BiTNode &e, int Value)
{
    if(!T)
        return;
    e.data=Value;
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

BiTNode* LeftChild(BiTree T,BiTNode e)
{
    if(!T)
        return NULL;
    else
        return e.left;

}

BiTNode* RightChild(BiTree T,BiTNode e)
{
    if(!T)
        return NULL;
    else
        return e.right;

}

BiTNode* LeftSibling(BiTree T,BiTNode e)
{
    if(!T||!Parent(T,&e))
        return NULL;
    else
    {
        return Parent(T,&e)->right;
    }

}

BiTNode* RightSibling(BiTree T,BiTNode e)
{
    if(!T||!Parent(T,&e))
        return NULL;
    else
    {
        return Parent(T,&e)->right;
    }

}

void InsertChild(BiTree T,BiTNode *p,int LR,BiTree c)
{
    if(LR==0)
    {
        BiTNode *temp=p->left;
        p->left=c;
        c->right=temp;

     }

    if(LR==1)
    {
        BiTNode *temp=p->right;
        p->right=c;
        c->left=temp;

    }

}

void DeleteChild(BiTree T,BiTNode *p,int LR)
{
    if(LR==0)
    {Destroy(p->left);
        p->left=NULL;
    }

    if(LR==1)
    {Destroy(p->right);
        p->right=NULL;
    }
}

bool PreOrderTraverse(BiTree T,int e)
{
    stack<BiTNode *> node;
    BiTNode *n=T;
    node.push(n);
    while(n!=NULL||!node.empty())
    {
        while (n!=NULL){
            if(n->data==e)
                return true;
            node.push(n);
            n=n->left;
        }
        if(!node.empty()){
            n=node.top();
            node.pop();
            n=n->right;

        }
    }
    return false;



}

bool MidOrderTraverse(BiTree T,int e) {
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
            if (n->data == e)
                return true;
            n = n->right;

        }
        
    }
    return false;
}



    bool AftOrderTraverse(BiTree T,int e){
        stack<BiTNode *> node;
        BiTNode *n = T;
        BiTNode *last=T;
        node.push(n);
        while(n!=NULL||node.empty()){
            while (n!=NULL){
                node.push(n);
                n=n->left;
            }
            n=node.top();
            if(n->right!=NULL||n->left==last){
                if (n->data == e)
                    return true;
                node.pop();
                last=n;
                n=NULL;
            }
            else{n=n->right;


            }

        }
    }






int main()
{
 BiTree T;
    CreateBiTee(T);
    cout<<"deep: "<<TreeDepth(T)<<endl;
    cout<<Value(T,T->left->left)<<" parent.data:";
    BiTNode *e=Parent(T,T->left->left);
    cout<<e->data<<" it RightSibling:";
    e=RightSibling(T,*e);
    cout<<e->data<<endl;
    
    if(PreOrderTraverse(T,4))
    cout<<"PreOrderTraverse(T,4) is true"<<endl;
    if(MidOrderTraverse(T,2))
    cout<<"MidOrderTraverse( T,2) is true"<<endl;
    if(AftOrderTraverse(T,1))
    cout<<"AftOrderTraverse(T,1) is true"<<endl;
    Destroy(T);
    

}
