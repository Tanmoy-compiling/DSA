#include <bits/stdc++.h>
using namespace std;

vector<int> getPath(vector<vector<int>> matrix,int sv,int tv,int v){
    queue<int> printvertices;
    vector<bool> visited(v,false);
    visited[sv] =true;
    printvertices.push(sv);
    map<int,int> m;

    while(!printvertices.empty()){

        int cv=printvertices.front();
        printvertices.pop();

        for(int i = 0;i<v;i++){
            if(i==cv) continue;
            
            if(matrix[cv][i] && visited[i]==false){
                printvertices.push(i);
                visited[i]=true;
                m[i]=cv;
            }
        }
    }

    vector<int> path;

    if(visited[tv]==false){
        cout<<"not found"<<endl;
        return path ;
    }

    auto it = m.find(tv);

    while(1){
        path.push_back(it->first); 
        if(it->second==sv){
            path.push_back(it->second);
            break;
        }
        it=m.find(it->second);
    }
    return path;
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
    cout<<"Enter the beggining vertex and target vertex"<<endl;
    int bv,tv; cin>>bv>>tv;
    
    vector<int> path = getPath(matrix,bv,tv,v);

    for(auto it : path)
     cout<<it<<" ";
    
    cout<<endl;
}