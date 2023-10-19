//
// Created by ASUS on 07-04-2023.
//
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
        }        cout<<"Enter right child of "<<front->data<<endl;
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

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
        if(root==NULL)
            return NULL;

        if(root->data==data){
            vector<int>* output=new vector<int>();
            output->push_back(root->data);
            return output;
        }

        vector<int>* leftOutput= getRootToNodePath(root->left,data);
        if(leftOutput!=NULL && data<root->data){
            leftOutput->push_back(root->data);
            return leftOutput;
        }

        vector<int>* rightOutput= getRootToNodePath(root->right,data);
        if(rightOutput!=NULL && data>root->data){
            rightOutput->push_back(root->data);
            return rightOutput;
        }
        else
            return NULL;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){

    BinaryTreeNode<int>* root= takeInputLevelWise();
    /*queue<BinaryTreeNode<int>*> printingNodes;
    printingNodes.push(root);
    printLevelWise(root,printingNodes);*/

    vector<int>* output= getRootToNodePath(root,8);
    for(int i = 0;i<output->size();i++){
        cout<<output->at(i)<<endl;
    }
        delete output;
}