#include <bits/stdc++.h>
using namespace std;

int countSteps(int n){
    int b=INT_MAX,c=INT_MAX;
    if(n==1)
        return 0;

    int a= countSteps(n-1);
    if(n%3 == 0)
    b= countSteps(n/3);
    if(n%2 == 0)
    c= countSteps(n/2);

    int result = min(a,min(b,c));
    
    return result+1;
}

int countSteps2(int n,vector<int> memo){
    if(n==1){
        memo[n]=0;
        return 0;
    }
    if(memo[n]!=-1)
        return memo[n];
    
    int a= countSteps2(n-1,memo);
    int b,c;b=c=INT_MAX;
    if(n%3==0)
    b = countSteps2(n/3,memo);
    if(n%2==0)
    c= countSteps2(n/2,memo);

    memo[n]= min(a,min(b,c))+1;

    return memo[n];
}

int countSteps3(int n, vector<int> &a){
    a[1]=0,a[1]=1,a[2]=1,a[3]=1;
    for(int i = 4;i<=n;i++){
        
        int b,c,d;b=c=d=INT_MAX;

        if(i%3==0)
            b=a[i/3]+1;
        
        if(i%2==0)
            c=a[i/2]+1;
        
        d=a[i-1]+1;

        a[i]=min(d,min(b,c));
    }
    return a[n];
}

int main(){
    cout<<"Enter the steps"<<endl;
    int n;cin>>n;
    // int result=countSteps(n);
    vector<int> memo(n+1,INT_MAX);
    // int result2=countSteps2(n,memo);
    int result2=countSteps3(n,memo);

    cout<<result2<<endl;
    for(auto &it: memo )
        cout<<it<<" ";
        
}