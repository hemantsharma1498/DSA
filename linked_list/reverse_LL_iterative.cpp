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


Node *reverseLinkedList(Node *head) {
    // Write your code here
	if(head==NULL||(*head).next==NULL) return head;
    
    Node *curr=head;
    Node *prev=NULL, *next=NULL;
    
    while(curr!=NULL){
        next=(*curr).next;
        (*curr).next=prev;
        
        prev=curr;
        curr=next;
    }
    
    return prev;
}
