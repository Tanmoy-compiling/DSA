#include <bits/stdc++.h>
using namespace std;

#define N 9

bool findEmptyLocation(vector<vector<int>> grid,int &row,int &col){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
} 

void printTable(vector<vector<int>> grid){
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafeInRow(vector<vector<int>> grid,int row,int num)
{
    for(int i = 0;i<N;i++){
        if(grid[row][i]==num)
            return false;
    }
    return true;
}

bool isSafeInColumn(vector<vector<int>> grid,int column,int num){
    for(int i = 0;i<N;i++){
        if(grid[i][column]==num)
            return false;
    }
    return true;
}

bool isSafeInGrid(vector<vector<int>> grid,int row,int col,int num){
    int rowFactor=row - (row%3);
    int columnFactor=col - (col%3);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(grid[i+rowFactor][j+columnFactor]==num)
                return false;
        }
    }
    return true;
}

bool isSafe(vector<vector<int>> grid,int row,int col,int num){
    if(isSafeInRow(grid,row,num) && isSafeInColumn(grid,col,num) && isSafeInGrid(grid,row,col,num))
        return true;
    return false;
}

bool solveSudoku(vector<vector<int>> grid)
{
    int row, col;
    if(!findEmptyLocation(grid,row,col)){
        printTable(grid);
        return true;
    }
    for(int i = 1;i<=N;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col]=i;
            if(solveSudoku(grid))
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> grid(N,vector<int> (N));

    for(int i = 0;i<N;i++){
        string s;
        cin>>s;
        for(int  j=0;j<s.length();j++){
            grid[i][j]=s[j]-'0';
        }
    }

    if(!solveSudoku(grid))
    {
        cout<<"not possible"<<endl;
    };


    return 0;
} /*306508400
  520000000
  087000031
  003010080
  900863005
  050090600
  130000250
  000000074
  005206300*/