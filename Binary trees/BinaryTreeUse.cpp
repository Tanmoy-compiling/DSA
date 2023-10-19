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

void printLevelWise(BinaryTreeNode<int>* root,queue<BinaryTreeNode<int>*> &printingNOdes){
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
    printLevelWise(root,printingNOdes);
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

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){
    // BinaryTreeNode<int>* root= new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    // root->left=node1;
    // root->right=node2;
    BinaryTreeNode<int>* root= takeInputLevelWise();
    queue<BinaryTreeNode<int>*> printingNodes;
    printingNodes.push(root);
    printLevelWise(root,printingNodes);
    // printTree(root);
    delete root;
}