#include <bits/stdc++.h>

using namespace std;

int minCostPath(vector<vector<int>> M,int m,int n){
    if(m==M.size()-1 && n==M[0].size()-1)
    {
        return M[m][n];
    }
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if((m+1)<M.size() && (n+1)<M[0].size())
   a= minCostPath(M,m+1,n+1);
    if((m+1)<M.size())
    b= minCostPath(M,m+1,n);
    if((n+1)<M[0].size())
    c= minCostPath(M,m,n+1);

    return min(a,min(b,c))+M[m][n];
}

int minCostPath2(vector<vector<int>>v,int m,int n){
    vector<int> output(n+1,-1);
    
}

int main(){
    vector<vector<int>> M={{3,4,1,2},{2,1,8,9},{4,7,8,1}};
    int result=minCostPath2(M,M.size(),M[0].size());
    cout<<result<<endl;
}