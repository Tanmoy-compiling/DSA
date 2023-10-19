#include <bits/stdc++.h>

using namespace std;

int fibo_2(int n,vector<int>& dp){
    if(n==0 || n==1)
        return n;
    
    if(dp[n] != -1)
        return dp[n];
    
    dp[n]=fibo_2(n-1,dp)+fibo_2(n-2,dp);

    return dp[n];
}

int main(){
    int n = 10;
    vector<int> dp(n+1,-1);

    int result=fibo_2(n,dp);
     cout<<result<<endl;
    
    return 0;
}