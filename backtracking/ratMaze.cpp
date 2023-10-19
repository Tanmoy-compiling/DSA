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

void findPath(vector<vector<int>> v,int row,int col, vector<vector<int>> solution){
    if(row == v.size()-1 && col==v[0].size()-1)
    {
        solution[row][col] =1;
        printTable(solution);
        solution[row][col]=0;
        return;
    }
        if(v[row][col]==0 || solution[row][col]==1 || row>=v.size() || row<0 || col>=v[0].size() || col<0)
            return;
        solution[row][col]=1;

        findPath(v,row,col+1,solution);
        findPath(v,row+1,col,solution);
        findPath(v,row-1,col,solution);
        findPath(v,row,col-1,solution);

        solution[row][col]=0;
    return;
}

int main(){
    vector<vector<int>> v={{1,0,1},{1,1,1},{1,1,1}};
    vector<vector<int>> solution(3,vector<int> (3,0));
    findPath(v,0,0,solution);
}