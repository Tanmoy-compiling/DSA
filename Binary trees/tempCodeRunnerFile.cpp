BinaryTreeNode<int> arr_to_binary(BinaryTreeNode<int> root,vector<int>& v,int si,int ei){
    if(si>ei)
        return root;
    int mid=(si+ei)/2;
    root->data=mid;
    arr_to_binary(root->left,v,si,mid-1);
    arr_to_binary(root->data,v,mid+1,ei);

    return root;
}