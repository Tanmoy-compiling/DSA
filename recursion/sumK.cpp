#include <bits/stdc++.h>
using namespace std;

void printtemp(vector<int> &temp){
    for(auto &it : temp){
        cout<<it<<" ";
    }
    cout<<endl;
}


    void subsetHelper(vector<int> input,int n,vector<vector<int>> &output,int k ,vector<int> &temp,int si){
        // printtemp(temp);
        if(k==0){
            output.push_back(temp);        
            return ;
        }
        if(si==n || k<0){
            return;
        }

        
            temp.push_back(input[si]);
            subsetHelper(input,n,output,k-input[si],temp,si+1);
            temp.pop_back();
        

        subsetHelper(input,n,output,k,temp,si+1);

        return ;
        
    }

    vector<vector<int>> subsetSumToK(vector<int> input,int n,vector<vector<int>> &output,int k ){
        vector<int> temp;
        // cout<<1<<endl; 
        subsetHelper(input,n,output,k,temp,0);
        return output;
    }


void printOutput(vector<vector<int>> output){
     for (const auto& row : output) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main(){
    int n=9;
    vector<int> v={5,12,3,17,1,18,15,3,17};
    int target=6;
    vector<vector<int>> output;
    // cout<<1<<endl;
    subsetSumToK(v,n,output,target);
    cout<<endl;
    printOutput(output);
}
