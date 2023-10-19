#include <bits/stdc++.h>
using namespace std;

int countStairs(int a,int& count){
    if (a < 0) return 0;
    if(a==0) {
        count++;
        return count;
    }

    return countStairs(a-3,count) + countStairs(a-2,count) + countStairs(a-1,count);
}


int main()
{
    int a; cout<<"Enter number of staircase"<<endl;
    cin>>a;
    int count=0;
    countStairs(a,count);
    cout<<count;
}