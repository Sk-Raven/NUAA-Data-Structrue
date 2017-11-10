#include <iostream>
using namespace std;
class QNode{
public:
    int data;
    QNode *next;
    QNode()
    {}
    QNode(int e)
    {
        data=e;
    }
};

class LinkQueue
{
public:
    QNode *front;
    QNode *rear;
};

bool InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=new QNode();
    if(!Q.front)
        return false;
    Q.front->next=NULL;
    return true;
}

bool DestroyQueue(LinkQueue &Q){
    while(Q.front){
        Q.rear=Q.front->next;
        delete[]Q.front;
        Q.front=Q.rear;
    }
    return true;
}

bool EnQueue(LinkQueue &Q,int e){
    QNode *p=new QNode();
    if(!p)
        return false;
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return true;
}

bool DeQueue(LinkQueue &Q,int &e){
    if(Q.front==Q.rear)
        return false;
    QNode *p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    delete[]p;
    return true;
}

bool ClearQueue(LinkQueue &Q) {
    DestroyQueue(Q);
    InitQueue(Q);
    return true;

}

int QueueLength(LinkQueue Q) {
    if(Q.front==Q.rear)
        return 0;
    QNode *p=Q.front->next;
    int num=1;
    while(p!=Q.rear)
    {
        p=p->next;
        num++;
    }
    return num;

}

bool GetHead(LinkQueue Q,int &e)
{
    if(QueueLength(Q)==0)
        return false;
    e=Q.front->next->data;
    return e;
}
bool visit(int e)
{
    return e==0;
}
bool QueueTraverse(LinkQueue Q,bool (*visit)(int))
{   if(QueueLength(Q)==0)
        return false;
    QNode *p=Q.front->next;
    while(p!=NULL)
    {
        if(visit(p->data))
            return true;
        else
            p=p->next;

    }
    return false;

}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    int e=3;
    printf("Init\n");
    for(int k=0;k<3;k++)
        EnQueue(Q,k);
    printf("QueueLength=%d\n",QueueLength(Q));
    EnQueue(Q,e);
    printf("EnQueue,Q.rear->data=%d\n",Q.rear->data);
    DeQueue(Q,e);
    printf("DeQueue,Q.rear->data=%d\n",Q.rear->data);
    GetHead(Q,e);
    printf("Q.front->data=%d\n",e);
    if(!QueueTraverse(Q,visit))
        printf("0 not exist\n");
    DestroyQueue(Q);
    printf("Destroy");


}
