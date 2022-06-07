BinaryTreeNode<int>* recurTree(int* preorder, int* inorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end){
    if(inorder_start>inorder_end) return NULL;
    
    
    int root_data=preorder[preorder_start];
    
    int root_index=-1;
    for(int i=inorder_start;i<=inorder_end;i++){
        if(inorder[i]==preorder[preorder_start]){
            root_index=i;
            break;
        }
    }
    
    
    
    int left_preorder_start=preorder_start+1;
    
    int left_inorder_start=inorder_start;
    int left_inorder_end=root_index-1;
    
    int left_preorder_end=left_inorder_end-left_inorder_start+left_preorder_start;
    
    int right_preorder_start=left_preorder_end+1;
    int right_preorder_end=preorder_end;
    int right_inorder_start=root_index+1;
    int right_inorder_end=inorder_end;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(root_data);
    
    (*root).left=recurTree(preorder, inorder, left_preorder_start, left_preorder_end, left_inorder_start, left_inorder_end);
    (*root).right=recurTree(preorder, inorder, right_preorder_start, right_preorder_end, right_inorder_start, right_inorder_end);
    
    return root;
    
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
    return recurTree(preorder, inorder, 0, preLength-1, 0, inLength-1);
}
