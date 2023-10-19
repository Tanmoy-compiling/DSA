#include <bits/stdc++.h>
using namespace std;

int minCount2(int n,vector<int> &memo){
    if(n<=3){
        memo[n]=n;
        return n;
    }

    if(memo[n]!=-1)
        return memo[n];

    int result=n;

    for(int i = 2;i<=sqrt(n);i++){
        int sq=i*i;
       result=min(result,minCount2(n-sq,memo)+1);
    }
    memo[n]=result;
    return memo[n];
}

int minCount3(int n,vector<int> dp){
    dp[0]=0;dp[1]=1;dp[2]=2;dp[3]=3;
    for(int i =4;i<=n;i++){
         for(int j = 0;j*j<=n;j++){
            int sq=j*j;
            if(i-sq>=0)
            dp[i]=min(dp[i],dp[i-sq]+1);
         }
    }
    cout<<dp[n]<<endl;
    return dp[n];
}

int minCount(int n){
    if(n<=3){
        return n;
    }
    int result=n;

    for(int i = 2;i<=sqrt(n);i++){
        int sq=i*i;
        result=min(result,minCount(n-sq)+1); 
        cout<<result<<endl;  
    }
    return result;
}

int main(){
    cout<<"Enter the no"<<endl;
    int n;cin>>n;
    vector<int> memo(n+1,INT_MAX);
    int result=minCount3(n,memo);
}