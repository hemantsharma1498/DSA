
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    
    TreeNode<int>* max=root;
    TreeNode<int>* rec;
    
    for(int i=0;i<((*root).children).size();i++){
    	rec=maxDataNode((*root).children[i]);
        if((*max).data<(*rec).data) max=rec;
    }
    
    return max;
}
