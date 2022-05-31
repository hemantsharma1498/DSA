//Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
//Note: Return NULL if no node is present with the value greater than n.


TreeNode<int>* getNextLargerElement(TreeNode<int> *root, int n) {
    
    if(root==NULL)
        return NULL;		///edge case
  
    TreeNode<int>*max =NULL;
    
    if(root->data > n)
        max=root;
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>*childmax= getNextLargerElement(root->children[i], n);
        
        if(childmax==NULL)
        {continue;}
        
        else
        {
            if(max==NULL)
                max=childmax;
            else if(childmax->data > n  && childmax->data < max->data)
                max= childmax;
        }
    }
    
    return max;

}
