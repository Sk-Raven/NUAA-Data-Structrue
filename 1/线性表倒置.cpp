#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;
void swp(int *l,int n)
{
	for(int i=0;i<n/2;i++)
	swap(l[i],l[n-i-1]);
}
int main()
{
	int l[10];
	for(int k=0;k<10;k++)
	l[k]=k;
	for(int k=0;k<10;k++)
	printf("%d ",l[k]);
	printf("\nµ¹ÖÃ\n");
	swp(l,sizeof(l)/sizeof(int));
	for(int k=0;k<10;k++)
	printf("%d ",l[k]);
	return 0;
}

