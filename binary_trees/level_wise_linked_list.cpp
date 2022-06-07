//Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<Node<int>*> list;
    if(root==NULL){
        return list; 
    }
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);
    nodes.push(NULL);
    
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
    
	while(!nodes.empty()){
        
        BinaryTreeNode<int>* front=nodes.front();
        
        if(front != NULL) {
            Node<int>* n=new Node<int>((*front).data);
            
            if(head==NULL){
				head=n;
                tail=n;
                
            }
            else{
                (*tail).next=n;
                tail=n;
            }
        }
        nodes.pop(); 
        if((*front).left) nodes.push((*front).left);
        if((*front).right) nodes.push((*front).right);
        if(nodes.front() == NULL)
        {
            nodes.pop();
            list.push_back(head);
            head = NULL;
            tail = NULL;
            if(nodes.size())
            	nodes.push(NULL);
        }
    }
	
	return list;

}
