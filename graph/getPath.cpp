#include <bits/stdc++.h>
using namespace std;

vector<int> print(vector<vector<int>> matrix,vector<bool> &visited,int sv,int tv,int v,vector<int> &path){
    visited[sv]=true;
    if(sv==tv)
    {
        path.push_back(sv);
        return path;
    }
    for(int i = 0;i<v;i++){
        if(!visited[i] && matrix[sv][i]==1){
            visited[i]=true;
            print(matrix,visited,i,tv,v,path);
            if(path.size()!=0)
            path.push_back(sv);
        }
    }
    return path;
}

int main(){
    int v,e;
    cout<<"Enter no of vertices and edges"<<endl;
    cin>>v>>e;
    vector<bool> visited(v,false);
    vector<vector<int>> matrix(v,vector<int>(v,0));
    for(int i = 0;i<e;i++){
        int sv,ev;  
        cout<<"Enter starting vertex and end vertex"<<endl;
        cin>>sv>>ev;
        matrix[sv][ev]=matrix[ev][sv]=1;
    }
    cout<<"Enter start vertex and target vertex"<<endl;
    int sv,tv;cin>>sv>>tv;
    vector<int> path;
    print(matrix,visited,sv,tv,v,path);     
    cout<<endl;
    for(int i = 0;i<path.size();i++){
        cout<<path[i]<<endl;
    }
}