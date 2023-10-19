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

bool checkNode(BinaryTreeNode<int>* root,int check){
    if(!root)
        return false;
    if(root->data==check)
        return true;
    
    return checkNode(root->left,check)||checkNode(root->right,check);
}

BinaryTreeNode<int>* buildTreeHelper(vector<int>& in,vector<int>& pre,int inS,int inE,int preS,int preE){
    if(inS>inE)
        return NULL;
    
    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i = inS;i<=inE;i++){
        if(in[i]==rootData)
        {
            rootIndex= i;
            break;
        }
    }
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;
    int lPreE=lInE-lInS+lPreS;
    int rPreS=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1;
    int rInE=inE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    root->left= buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
    root->left= buildTreeHelper(in,pre,rInS,rInE,rPreS,rPreE);

    return root;
}

BinaryTreeNode<int>* buildTree(vector<int>& in,vector<int>& pre,int size){
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}

int main(){
   
    vector<int> in= {4,2,5,1,8,6,9,3,7};
    vector<int> pre={1,2,4,5,3,6,8,9,7};
    BinaryTreeNode<int>* root=buildTree(in,pre,9);
    queue<BinaryTreeNode<int>*> printingNodes;
    printingNodes.push(root);
    printLevelWise(root,printingNodes);
     delete root;
}