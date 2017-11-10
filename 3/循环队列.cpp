#include <iostream>
#include <malloc.h>
#include <algorithm>
using namespace std;
class SqQueue{
public:
    int *base;
    int front;
    int rear;
};

bool InitQueue(SqQueue &Q){
    Q.base=(int *)malloc(10* sizeof(int));
    if(!Q.base)
        return false;
    Q.front=Q.rear=0;
    return true;
}

bool EnQueue(SqQueue &Q,int e){

        Q.base[Q.rear]=e;     
        Q.rear=(Q.rear+1)%10;
        return true;

}

bool DestroyQueue(SqQueue &Q){
    free(Q.base);
    return true;
}

int Queuemax(SqQueue Q)
{   int a[10];
    for(int k=0;k<10;k++)
        a[k]=Q.base[k];
    sort(a,a+10);
    printf("max=%d",a[9]);
}
using namespace std;
int main()
{
    SqQueue Q;
    InitQueue(Q);
    for(int k=0;k<100;k++)
        EnQueue(Q,k);
    Queuemax(Q);
    DestroyQueue(Q);

}
