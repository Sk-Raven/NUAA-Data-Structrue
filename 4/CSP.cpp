#include <iostream>
#include <vector>
using namespace std;
vector<int> seats(20,5);

void printSeats(int a, int b) {
    for(int k=1; k<=b; k++)
    {
        printf("%d ", a*5+k+5-seats[a]);
    }
}

void requst(int num) {
    for(int k=0; k<20; k++)
    {
        if(seats[k] >= num)
        {
            printSeats(k, num);
            seats[k] -= num;
            num = 0;
        }
    }
    int i = 0;

    while(num) {
        if(seats[i] > 0) {
            if(num <= seats[i]) {
                printSeats(i, num);
                num = 0;
                seats[i] -= num;
            }
            else {
                printSeats(i, seats[i]);
                num -= seats[i];
                seats[i] = 0;
            }
        }
        i++;
    }
    printf("\n");
}

int main() {
    int a,r;
    scanf("%d", &a);
    for(int k=0; k<a; k++) {
        scanf("%d", &r);
        requst(r);
    }
}
