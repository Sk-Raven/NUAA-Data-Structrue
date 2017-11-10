#include <iostream>
#include <vector>
using namespace std;
class window{
public:
    int x1,x2,y1,y2,num;
    window(int a,int b,int c,int d,int n){
        x1=a;
        y1=b;
        x2=c;
        y2=d;
        num=n;
    }
    bool isin(int x,int y){
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }
};
int main()
{int n,m,x1,x2,y1,y2,x,y;
    bool flag=false;
    vector<window> a;
    cin>>n>>m;
    for(int k=0;k<n;k++)
    {   cin>>x1>>y1>>x2>>y2;
        window temp=window(x1,y1,x2,y2,k+1);
        a.push_back(temp);
    }
    for(int k=0;k<m;k++)
    {
        cin>>x>>y;
        for(int k=n-1;k>=0;k--)
        {
            if(a[k].isin(x,y))
            {
                window temp=window(a[k].x1,a[k].y1,a[k].x2,a[k].y2,a[k].num);
                a.erase(a.begin()+k);
                a.push_back(temp);
                printf("%d\n",a.back().num);
                flag=true;
                break;
            }


        }
        if(flag==false)
            printf("IGNORED\n");
        else
            flag=false;

    }


}
