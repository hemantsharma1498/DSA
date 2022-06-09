class BST {
    BinaryTreeNode<int>* root;
   public:
    BST() { 
        root=NULL;
    }

	private:
    BinaryTreeNode<int>* min(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        BinaryTreeNode<int>*m=root;
        while(m->left!=NULL)
        {
            m=m->left; 
        }
        return m;
        
    }
    BinaryTreeNode<int>* deletePrivate(int data, BinaryTreeNode<int>* node){
        if(!node) return NULL;
        
        if(data>node->data){
            node->right=deletePrivate(data, node->right);
        }
        else if(data<node->data){
            node->left=deletePrivate(data, node->left);
        }
        else{
    		if(!node->left && !node->right){
                delete node;
                return NULL;
            }
            else if(!node->right){
               BinaryTreeNode<int>* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else if(!node->left){
               BinaryTreeNode<int>* temp=node->right;
                node->right=NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minimum=min(node->right);
                
                int rightMin=minimum->data;
                node->data=rightMin;
                node->right=deletePrivate(rightMin, node->right);
                return node;
            
            }
        }
    }
	
    public:
    void remove(int data) { 
        root=deletePrivate(data, root);
    }
	
    private:
    void printPrivate(BinaryTreeNode<int>* root){
        if(root==NULL) return;
        
    	cout<<root->data<<":";
        
       if(root->left!=NULL){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        
        printPrivate(root->left);
        printPrivate(root->right);
    }
    
    public:
    void print() { 
        printPrivate(root);
    }
   
    private:
    BinaryTreeNode<int>* insertPrivate(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int>* newNode=new BinaryTreeNode<int>(data);
            return newNode;
        }
        
        if(node->data>=data){
            node->left=insertPrivate(data, node->left);
        }
    	else{
            node->right=insertPrivate(data, node->right);
        }
        
        return node;
        
    }
    
    
	public:
    void insert(int data) { 
        this->root=insertPrivate(data, this->root);
    }
	
    private:
    bool searchPrivate(BinaryTreeNode<int>* root, int data){
        if (root== NULL) {
            return false;
        }

        if (root->data == data) {
            return true;
        } else if (data < root->data) {
            return searchPrivate(root->left, data);
        } 

        rturn searchPrivate(root->right, data);
        
    }
   
    public:
    bool search(int data) {
        return searchPrivate(root, data);
       
    }
};
