#include <bits/stdc++.h>
using namespace std;

bool hasPath(vector<vector<int>> matrix,int sv,int ev,int v,int e){
    queue<int> node; 
    node.push(sv);
    vector<bool> visited(v,false);
    visited[sv]=true;
    while(!node.empty()){
        int cv=node.front(); node.pop();
        for(int i = 0;i<e;i++){
            if(matrix[cv][i] && !visted[i]){
                node.push(i);
                visited[i]= true;
            }
            if(visited[ev])
                return true;
        }
    }
    return false;
}

int main(){
    cout<<"Enter the no of vertices and edges"<<endl;
    int v,e;
    cin>>v>>e;
    vector<vector<int>> matrix(v,vector<int> (v,0));

    for(int i = 0;i<e;i++){
        int sv,ev; cout<<"Enter starting and ending vertex"<<endl;
        cin>>sv>>ev;
        matrix[sv][ev]=1;
        matrix[ev][sv]=1;
    }
    int sv,ev; cout<<"Enter starting and target vertex"<<endl; 
    cin>>sv>>ev;
    cout<<hasPath(matrix,sv,ev,v,e)<<endl;
}