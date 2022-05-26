 
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


Node *midway(Node *head){
    if(head==NULL||((*head).next)==NULL) return head;
    
    Node *slow=head, *fast=(*head).next;
    
    while(fast!=NULL&&(*fast).next!=NULL){
        slow=(*slow).next;
        fast=(*(*fast).next).next;
    }
    
    return slow;
    
    
}

Node *merge(Node *head1, Node *head2)
{
    //Write your code here
    
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    if(head1==NULL&&head2==NULL) return NULL;
    
    Node *fhead=NULL;
    Node *ftail=NULL;
    
    if((*head1).data<(*head2).data){ 
        fhead=head1; ftail=head1;
    	head1=(*head1).next;    
    }
    else{ 
        fhead=head2;ftail=head2; head2=(*head2).next;
    }
    
    while(head1!=NULL&&head2!=NULL){
    	if((*head1).data<=(*head2).data){
			(*ftail).next=head1;
            head1=(*head1).next;
        }
        else {
            (*ftail).next=head2; head2=(*head2).next;
        }
        
        ftail=(*ftail).next;
    }  
    
    if(head1!=NULL){
        (*ftail).next=head1;
        
    }
    if(head2!=NULL) (*ftail).next=head2;
    
    
    
    return fhead;
    
}


Node *mergeSort(Node *head)
{
	
    if(head==NULL||(*head).next==NULL) return head;
    
    Node *mid=midway(head);
    
    Node *old_head=head;
    Node *new_head=(*mid).next;
    
    (*mid).next=NULL;
    
    Node *fhead1=mergeSort(old_head);
    Node *fhead2=mergeSort(new_head);
    
    Node *ultimate_head=merge(fhead1, fhead2);
    
    return ultimate_head;
}


