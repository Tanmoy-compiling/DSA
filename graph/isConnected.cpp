#include <bits/stdc++.h>
using namespace std;


bool isConnected(vector<vector<int>> matrix,int sv,int v){
    queue<int> printvertices;
    vector<bool> visited(v,false);
    visited[sv] =true;
    printvertices.push(sv);

    while(!printvertices.empty()){

        int cv=printvertices.front();
        printvertices.pop();

        for(int i = 0;i<v;i++){
            if(i==cv) continue;
            
            if(matrix[cv][i] && visited[i]==false){
                printvertices.push(i);
                visited[i]=true;
            }
        }
    }

    for(int i = 0;i<visited.size();i++){
        if(visited[i]==false)
            return false;
    }

    return true;
}

int main(){
    cout<<"Enter no of vertices and edges"<<endl;
    int v,e;cin>>v>>e;
    vector<vector<int>> matrix(v,vector<int>(v,0));
    for(int i = 0;i<e;i++){
        cout<<"Enter the starting vertex and ending vertex"<<endl;
        int sv,ev;cin>>sv>>ev;
        matrix[sv][ev] =1;
        matrix[ev][sv]= 1;
    }

    cout<<"Enter the beggining vertex"<<endl;
    int bv; cin>>bv;

    cout<<isConnected(matrix,bv,v)<<endl;
}