#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
#include "linkedNode.h"

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

Node<int>* insertEnd(Node<int>* head,int item){
    Node<int>* temp= new Node<int>(item);
    Node<int>* ptr= head;
    if(head==NULL) {
        head = temp;
    }
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;

    }
    return head;
}

void printList(Node<int> *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node<int>* BstToLL(BinaryTreeNode<int>* root,Node<int>* head){

     if(root==NULL){
         return head;
     }
    head=BstToLL(root->left,head);
//    if(head==NULL)
//        head=insertEnd(head,root->data);
//    else
       head= insertEnd(head,root->data);
    head=BstToLL(root->right,head);

    return head;
}


int main() {
    BinaryTreeNode<int>* root= takeInputLevelWise();
    Node<int> *head = NULL;
    head= BstToLL(root,head);
    printList(head);
   /* queue<BinaryTreeNode<int>*> printingNodes;
    printingNodes.push(root);
    printLevelWise(root,printingNodes);*/
    delete root;
}
