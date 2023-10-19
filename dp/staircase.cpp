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

int countStairs2(int n,vector<int> memo){
    if(n<0) return 0;
    if(n==0){
        return 1;
    }
    if(memo[n]!=-1)
        return memo[n];
    
    memo[n]= countStairs2(n-3, memo)+countStairs2(n-2,memo)+countStairs2(n-1,memo);

    return memo[n];
    
}

int countStairs3(int n){
    int a=1,b=1,c=2,d;
    for(int i = 0;i<=n-3;i++){
        d=a+b+c;
        a=b;b=c;c=d;
    }
    return c;
}

int main()
{
    int a; cout<<"Enter number of staircase"<<endl;
    cin>>a;
    int count=0;
    vector<int> memo(a+1,-1);
    count=countStairs3(a);
    cout<<count;
}