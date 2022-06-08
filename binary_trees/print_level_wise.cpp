void printLevelWise(BinaryTreeNode<int> *root) {
    
    if(!root) return;
    
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);
  
    while(!nodes.empty()){
        BinaryTreeNode<int>* current=nodes.front();
        nodes.pop();
        cout<<(*current).data<<":";
        
        if((*current).left){
            nodes.push((*current).left);
            cout<<"L:"<<(*(*current).left).data;
        }
        else cout<<"L:-1";
        
        cout<<",";
        
        if((*current).right){
            nodes.push((*current).right);
            cout<<"R:"<<(*(*current).right).data;
        }
        else cout<<"R:-1";
    	
        cout<<endl;
    
    }
}
