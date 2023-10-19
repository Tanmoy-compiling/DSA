#include <bits/stdc++.h>
using namespace std;

int matchString(string a,string b,vector<vector<int>> output){
    if(a.size()==0 || b.size()==0)
        return max(a.size(),b.size());
    
    int m = a.size();
    int n = b.size();

    if(output[m][n] != -1)
        return output[m][n];

    int ans ;

    if(a[0]==b[0])
         ans= matchString(a.substr(1),b.substr(1),output);
 
    else{
    int x=matchString(a,b.substr(1),output);
    
    int y= matchString(a.substr(1),b,output);

    int z= matchString(a.substr(1),b.substr(1),output);

    ans= min(x,min(y,z))+1;
    }

    output[m][n]=ans;

    return ans;

}

int main(){
    string a,b;
    cout<<"Enter the strings"<<endl;
    cin>>a>>b;
    int m = a.size();
    int n = b.size();
    vector<vector<int>>  output(m+1,vector<int> (n+1,-1));
    int result =matchString(a,b,output);
    cout<<result<<endl;
}