BinaryTreeNode<int>* recurTree(int* input, int si, int ei){
    if(si>ei) return NULL;
    
    int mid=(si+ei)/2;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    
    // root->data=input[mid];
    
     root->left=recurTree(input, si, mid-1);
    root->right=recurTree(input, mid+1, ei);
   
    
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    
    return recurTree(input, 0, n-1);
}
