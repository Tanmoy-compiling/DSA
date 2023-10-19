#include <bits/stdc++.h>

using namespace std;


int findSpace(grid){
    for(int i = 0;i<10;i++){
        for(int j=0;j<10;j++){
            if(grid[i][j]=='-')
                return 1;
        }
    }
    return 0;
}

int verticalSpace(vector<vector<char>> grid,int num){
    int count=0
    int max=0;
    for(int i = 0;i<10;i++){
        if(grid[i][num]!='+'){
            count++;
        }
        else{
            count=0;
            if(count>max)
            max=count;
        }
    }
    return max;
}

void crossword(vector<vector<char>> grid,vector<string> word,int num){

    if(findSpace(grid)==0){
        printTable(grid)
        return;
    }

    for(int i = 0;i<10;i++){
    verticalSpace(grid,i);
    }

}

int main(){
     vector<vector<char>> grid(10,vector<char>(10));


     for(int i = 0;i<10;i++){
        string s;
        cin>>s;
        for(int  j=0;j<s.length();j++){
            grid[i][j]=s[j];
        }
    }

    vector<string> word={"california","nigeria","canada","telaviv"};

    crossword(grid,word,10);
}