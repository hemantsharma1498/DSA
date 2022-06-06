BinaryTreeNode<int>* recurTree(int* postorder, int* inorder, int postorder_start, int postorder_end, int inorder_start, int inorder_end){
    if(inorder_start>inorder_end){
        return NULL;
    }
    
    int root_data=postorder[postorder_end];
    
    
    int root_index=-1;
    
	for(int i=inorder_start;i<=inorder_end;i++){
        if(inorder[i]==postorder[postorder_end]){
            root_index=i;
            break;
        }
    }
    
    
    int left_postorder_start=postorder_start;
    
    int left_inorder_start=inorder_start;
    int left_inorder_end=root_index-1;
	
    
    int left_postorder_end=left_inorder_end-left_inorder_start+left_postorder_start;
    
    int right_postorder_end=postorder_end-1;
    int right_postorder_start=left_postorder_end+1;
	int right_inorder_start=root_index+1;
    int right_inorder_end=inorder_end;
    
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(root_data);
    (*root).left=recurTree(postorder, inorder, left_postorder_start, left_postorder_end, left_inorder_start, left_inorder_end);
    (*root).right=recurTree(postorder, inorder, right_postorder_start, right_postorder_end, right_inorder_start, right_inorder_end);
    
    return root;
    
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    
    return recurTree(postorder, inorder, 0, inLength-1, 0, inLength-1);
}
