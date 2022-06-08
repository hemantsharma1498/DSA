//Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

void zigZagOrder(BinaryTreeNode<int> *root) {
    
    if(!root)
     return;
    
    stack<BinaryTreeNode<int> *> nodes;
    stack<BinaryTreeNode<int> *> rev_nodes;
    
    nodes.push(root);
    
    while(!nodes.empty()){
        
        while(!nodes.empty()){
            BinaryTreeNode<int>* current=nodes.top();
            cout<<(*current).data<<" ";
            nodes.pop();
            
            if((*current).left){
                rev_nodes.push((*current).left);
            }
            if((*current).right){
                rev_nodes.push((*current).right);
            }
        }
        
        cout<<endl;
        
        while(!rev_nodes.empty()){
            BinaryTreeNode<int>* current=rev_nodes.top();
            cout<<(*current).data<<" ";
            rev_nodes.pop();
            
            if((*current).right){
                nodes.push((*current).right);
            }
            if((*current).left){
                nodes.push((*current).left);
            }
        }
        
        cout<<endl;
        
    }
    

}
