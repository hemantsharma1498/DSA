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


Node *midPoint(Node *head)
{
    // Write your code here
 	if(head==NULL||head->next==NULL) return head;   
    
    Node *slow=head;
    Node *fast=(*head).next;
    
   
    
    
    while(fast!=NULL&&(*fast).next!=NULL){
		slow=(*slow).next;
        fast=(*(*fast).next).next;
    }
    
    return slow;
    
}
