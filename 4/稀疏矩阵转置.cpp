#include <iostream>
#include <algorithm>
using namespace std;
class point{
public:
    int line;
    int row;
    int data;
 void operator =(point a)
 {
     line=a.line;
     row=a.line;
     data=a.data;
 }

};


class Matrix{
public:
    int a;
    int b;
    int num;
    point *data;
    Matrix(int c,int d,int e){
        a=c;
        b=d;
        e=num;
        data=new point[e];
    }
    
    

};
int main(){
    int a,b,c;
    int line,row,data;
    cin>>a>>b>>c;
    Matrix matrix=Matrix(a,b,c);
    for(int k=0;k<c;k++)
    {
        cin>>line>>row>>data;
        matrix.data[k].line=line;
        matrix.data[k].row=row;
        matrix.data[k].data=data;
    }
    Matrix matrix1=Matrix(b,a,c);
    
    for(int k=0;k<c;k++){
        matrix1.data[k].row=matrix.data[k].line;
        matrix1.data[k].line=matrix.data[k].row;
        matrix1.data[k].data=matrix.data[k].data;
    }

    for(int k=0;k<c-1;k++)
        for(int j=0;j<c-1-k;j++)
        {   
            if(matrix1.data[j].line>matrix1.data[j+1].line)
                {
                	int temp1=matrix1.data[j].line;
                	int temp2=matrix1.data[j].row;
                	int temp3=matrix1.data[j].data;
                	matrix1.data[j].line=matrix1.data[j+1].line;
                	matrix1.data[j].row=matrix1.data[j+1].row;
                	matrix1.data[j].data=matrix1.data[j+1].data;
                	matrix1.data[j+1].line=temp1;
                	matrix1.data[j+1].row=temp2;
                	matrix1.data[j+1].data=temp3;
				}
        }
        cout<<endl<<"×ªÖÃºó"<<"line="<< matrix1.a<<"   row="<<matrix1.b<<endl;
    for(int k=0;k<c;k++)
        cout<< matrix1.data[k].line<<" "<<matrix1.data[k].row<<" "<<matrix1.data[k].data<<endl;

}
