int minCount3(int n,vector<int> dp){
    dp[0]=0;dp[1]=1;dp[2]=2;dp[3]=3;
    for(int i =4;i<=n;i++){
         for(int j = 0;j*j<=n;j++){
            int sq=j*j;
            if(i-sq>=0)
            dp[i]=min(dp[i],dp[i-sq]+1);
         }
    }
    return dp[n];
}