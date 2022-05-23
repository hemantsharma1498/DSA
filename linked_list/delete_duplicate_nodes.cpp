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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    
    if(head==NULL) return NULL;
    
    Node *prev=head;
    Node *curr= head;
    
    
    while(prev!=NULL){
        
        curr=(*prev).next;
        if(curr!=NULL){
        	if((*prev).data==(*curr).data){
                (*prev).next=(*curr).next;
                delete(curr);
            }
            else prev=(*prev).next;
        }
        else break;
    }
    
    return head;
}
