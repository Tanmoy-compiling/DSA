#include <bits/stdc++.h>
#include "BinaryTreeNode.h"

using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of"<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(queue<BinaryTreeNode<int>*> &printingNOdes){
    if(printingNOdes.size()==0)
        return;
    queue<BinaryTreeNode<int>*> printingNodes;
    BinaryTreeNode<int>* front=printingNOdes.front();
    cout<<front->data<<":";
    if(front->left){
        cout<<"L:"<<front->left->data<<",";
        printingNOdes.push(front->left);
    }
    if(!front->left){
        cout<<"L:"<<-1<<",";
    }
    if(front->right){
        cout<<"R:"<<front->right->data;
        printingNOdes.push(front->right);
    }
    if(!front->right){
        cout<<"R:"<<-1;
    }
    cout<<endl;
    printingNOdes.pop();
    printLevelWise(printingNOdes);
}

void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left){
        cout<<"L"<<root->left->data;
    }
    if(root->right){
        cout<<"  R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* arr_to_binary(vector<int>& v,int si,int ei){
    if(si>ei)
        return NULL;
    int mid=(si+ei)/2;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(v[mid]) ;
    root->left=arr_to_binary(v,si,mid-1);
    root->right=arr_to_binary(v,mid+1,ei);

    return root;
}


//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){
    vector<int> v={1,2,3,4,5,6,7,8};
    // BinaryTreeNode<int>* root= takeInputLevelWise();
    queue<BinaryTreeNode<int>*> printingNodes;
    printingNodes.push(arr_to_binary(v,0,v.size()-1));
    printLevelWise(printingNodes);
}