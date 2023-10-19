#include <bits/stdc++.h>
using namespace std;

int editDistanceDP(string a,string b)
{

    int m = a.size();
    int n = b.size();
    vector<vector<int>> v(m+1,vector<int> (n+1));
    for(int i = 0;i<=m;i++) v[i][0]=i;
    for(int j=0;j<=n;j++) v[0][j]=j;

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                v[i][j]=v[i-1][j-1];
            }
            else{
                v[i][j]=min(v[i-1][j-1],min(v[i-1][j],v[i][j-1]))+1;
            }
        }
    }
    return v[m][n];
}

int main(){
    string a,b;
    cout<<"Enter a string"<<endl;
    cin>>a>>b;
    cout<<editDistanceDP(a,b)<<endl;
}