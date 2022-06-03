//You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node

void recurDepth(TreeNode<int>* root, int height){
    
    for(int i=0;i<((*root).children).size();i++){
        
        recurDepth(((*root).children[i]), height+1);
        
    }
    
    (*root).data=height;
}

void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    
    recurDepth(root, 0);
    
}
