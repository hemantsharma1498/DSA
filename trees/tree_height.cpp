int getHeight(TreeNode<int>* root) {
  
    
    int height=0;
    
    for(int i=0;i<(*root).children.size();i++){
        int rec_height=getHeight((*root).children[i]);
        if(rec_height>height) height=rec_height;
    }
    return height+1;
}
