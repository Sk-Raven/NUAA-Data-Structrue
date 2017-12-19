#include <iostream>
using namespace std;
void adjust(int a[],int i,int len)
{
    int temp=a[i];
    for(int k=2*i+1;k<len;k=k*2+1)
    {
        if(k!=len-1&&a[k]<a[k+1])
            k++;

        if(temp<a[k])
        {
            a[i]=a[k];
            i=k;
        }
        else
            break;
    }
    a[i]=temp;
}


void BuildMaxHeap(int a[], int len)
{
    for(int i=len/2-1; i>=0; i--)
        adjust(a, i, len);
}

void HeapSort(int a[], int n)
{
    BuildMaxHeap(a, n);
    for(int i=n-1; i>0; i--)
    {
        swap(a[0],a[i]);
        adjust(a, 0, i);
    }
}
int main()
{   int n[20];
    for(int k=0;k<20;k++)
        n[k]=20-k;

    HeapSort(n,20);
    for(int k=0;k<20;k++)
        printf("%d ",n[k]);
    return 0;
}
