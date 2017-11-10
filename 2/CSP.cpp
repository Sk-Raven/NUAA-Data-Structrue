#include <iostream>
#include <malloc.h>
#include <algorithm>

using namespace std;
int main()
{
    int length;
    cin>>length;
    int *a=(int *)malloc(length* sizeof(int));
    for(int i=0;i<length;i++)
        cin>>a[i];
    sort(a,a+length);
    if(length==1)
    {
    	cout<<a[length-1]<<endl;
    	free(a);
    	exit(0);
	}
	int temp=a[length/2];
	int num=0;
    for(int i=0;i<length;i++)
    if(temp==a[i])
    num++;
    
    if(length%2==num%2)
    cout<<temp;
    else
    cout<<"-1";
    	free(a);
}

