 
int getLeafNodeCount(TreeNode<int>* root) {
    
    int num=0;
    
    if(((*root).children).size()==0){
            return 1;
    }
    
    for(int i=0;i<((*root).children).size();i++){
        
        num+=getLeafNodeCount((*root).children[i]);
    }
    
    
    
    return num;
}
