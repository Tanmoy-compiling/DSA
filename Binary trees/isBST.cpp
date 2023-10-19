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

class IsBstReturn{
    public:
    bool isBst;
    int minimum;
    int maximum;
};

IsBstReturn isBst2(BinaryTreeNode<int>* root){
    if(root==NULL){
        IsBstReturn output;
        output.isBst = true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    IsBstReturn leftoutput = isBst2(root->left);
    IsBstReturn rightoutput = isBst2(root->right);
    int minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    int maximum=max(root->data,max(leftoutput.maximum,rightoutput.maximum));
    bool isBstFinal=(root->data>leftoutput.maximum)&&(root->data<=rightoutput.minimum)
    && leftoutput.isBst && rightoutput.isBst;

    IsBstReturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBst=isBstFinal;
    return output;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){
    BinaryTreeNode<int>* root= takeInputLevelWise();
    queue<BinaryTreeNode<int>*> printingNodes;
    printingNodes.push(root);
    printLevelWise(root,printingNodes);
    cout<<isBst2(root).isBst<<endl;

    delete root;
}