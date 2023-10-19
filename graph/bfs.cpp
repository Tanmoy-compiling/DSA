#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> matrix,int e,int sv,vector<bool>& visited,queue<int> &printingVertices)
{
    cout<<sv<<endl;
    visited[sv]=true;
    if(printingVertices.size()==0)
        return;
    
    for(int i = 0;i<e;i++)
    {
        if(i==sv) continue;
        if(matrix[sv][i]==1){
            if(visited[i]) continue;
            printingVertices.push(i);
        }
    }
    sv=printingVertices.front();
    printingVertices.pop();
    print(matrix,e,sv,visited,printingVertices);
}

int main(){
    cout<<"Enter vertices and edges"<<endl;
    int v,e,sv,ev;
    cin>>v>>e;
    vector<vector<int>> matrix(v,vector<int> (v,0));
    
    for(int i = 0;i<e;i++){
        cout<<"Enter starting vertex and end vertex"<<endl;
        cin>>sv>>ev;
        matrix[sv][ev]=matrix[ev][sv]=1;
    }
    queue<int> printVertice;
    vector<bool> visited(v,false);
    print(matrix,e,0,visited,printVertice);
}   