int height(BinaryTreeNode<int>* root){
    if(!root) return 0;
    
    int num=0;
    int leftheight=height((*root).left);
    int rightheight=height((*root).right);
    
    if(leftheight>rightheight) num=leftheight;
    else num=rightheight;
    
    return 1+num;
    
}



bool isBalanced(BinaryTreeNode<int> *root) {
       
    if (root == NULL) 
        return 1; 
    int leftheight=height(root->left);
	int rightheight=height(root->right);	
   
     if (!(abs(leftheight-rightheight)>1)&&isBalanced(root->left)&&isBalanced(root->right))
        return 1;
    
   return 0;
        
    
    
}
