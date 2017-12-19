#include <iostream>
using namespace std;
void Qsort(int a[],int low,int high)
{
    if(low>=high)
        return;

    int first=low;
    int last=high;
    int k=a[first];

    while (first<last)
    {
        while (first<last&&a[last]>=k)
            last--;

        a[first]=a[last];

        while(first<last&&a[first]<=k)
            first++;

        a[last]=a[first];
    }

    a[last]=k;
    Qsort(a,low,last-1);
    Qsort(a,last+1,high);

}
int main()
{
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    Qsort(a,0,8);

    for(int k=0;k<9;k++)
        printf("%d ",a[k]);
}