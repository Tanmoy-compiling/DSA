#include <bits/stdc++.h>

using namespace std;

void printTable(vector<vector<int>> v){
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v[0].size();j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}


bool checkInsertion(vector<vector<int>> v,int row ,int col){

    for(int  i = row-1;i>=0;i--){
        if(v[i][col]==1)
            return false;
    }

    for(int i = row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(v[i][j]==1)
            return false;
    }

    for(int i = row-1,j=col+1;i>=0 && j<v[0].size();i--,j++){
        if(v[i][j]==1)
            return false;
    }
    return true;
}


void queenInsertion(vector<vector<int>> v,int row){
    if(row==v.size()){
        printTable(v);
        return;
    }

    for(int i = 0;i<v[0].size();i++){
        if(checkInsertion(v,row,i)){
            v[row][i]=1;
            queenInsertion(v,row+1);
            v[row][i]=0;
        }
    }
    return;
}


int main(){
    vector<vector<int>> v(4, vector<int> (4, 0)) ;
    queenInsertion(v,0);
}