class Node {
     public:
         int data;
         Node *next;
         Node(int data)
         {
             this->data = data;
		     this->next = NULL;
	        }
};


int findNode(Node *head, int n){
    // Write your code here.
    int i=0;
    // if((*head).next==NULL&&(*head).data!=n) return -1;
    if(head==NULL)return -1;
    Node *current=head;
    while((*current).next!=NULL){
        if((*current).data==n) return i;
        i++;
        current=(*current).next;
    }
    
    
    
    return -1;
}
